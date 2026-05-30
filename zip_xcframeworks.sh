#!/bin/bash

set -euo pipefail

# ==========
# 配置
# ==========
ROOT_DIR="${1:-.}"

if ! command -v ditto >/dev/null 2>&1; then
  echo "❌ 未找到 ditto 命令，请在 macOS 环境下运行此脚本。"
  exit 1
fi

# 规范化路径
ROOT_DIR="$(cd "$ROOT_DIR" && pwd)"

echo "🗜️  开始压缩 ${ROOT_DIR} 下的 xcframework..."
echo "-------------------------------------"

# ==========
# 交互式输入版本号和时间戳选项
# ==========
echo ""
read -p "📝 请输入版本号（例如：2.1.8，留空则跳过版本号）: " VERSION
VERSION="${VERSION// /}"  # 去除空格

USE_TIMESTAMP=""
while [ -z "$USE_TIMESTAMP" ]; do
  read -p "🕐 是否添加时间戳？(y/n，默认: y): " USE_TIMESTAMP
  USE_TIMESTAMP="${USE_TIMESTAMP:-y}"
  USE_TIMESTAMP=$(echo "$USE_TIMESTAMP" | tr '[:upper:]' '[:lower:]')  # 转为小写（兼容 macOS bash 3.x）
  if [[ ! "$USE_TIMESTAMP" =~ ^(y|yes|n|no)$ ]]; then
    echo "⚠️  请输入 y 或 n"
    USE_TIMESTAMP=""
  fi
done

# 生成时间戳（格式：YYYYMMDDHHMMSS）
if [[ "$USE_TIMESTAMP" =~ ^(y|yes)$ ]]; then
  TIMESTAMP=$(date +"%Y%m%d%H%M%S")
else
  TIMESTAMP=""
fi

# 询问是否添加自定义文本
USE_CUSTOM_TEXT=""
while [ -z "$USE_CUSTOM_TEXT" ]; do
  read -p "✏️  是否添加自定义文本（如 fix1、beta 等）？(y/n，默认: n): " USE_CUSTOM_TEXT
  USE_CUSTOM_TEXT="${USE_CUSTOM_TEXT:-n}"
  USE_CUSTOM_TEXT=$(echo "$USE_CUSTOM_TEXT" | tr '[:upper:]' '[:lower:]')
  if [[ ! "$USE_CUSTOM_TEXT" =~ ^(y|yes|n|no)$ ]]; then
    echo "⚠️  请输入 y 或 n"
    USE_CUSTOM_TEXT=""
  fi
done

CUSTOM_TEXT=""
if [[ "$USE_CUSTOM_TEXT" =~ ^(y|yes)$ ]]; then
  read -p "📝 请输入自定义文本（例如：fix1、beta、hotfix 等）: " CUSTOM_TEXT
  CUSTOM_TEXT="${CUSTOM_TEXT// /}"  # 去除空格
  # 移除可能包含的不安全字符，只保留字母、数字、下划线、连字符
  CUSTOM_TEXT=$(echo "$CUSTOM_TEXT" | sed 's/[^a-zA-Z0-9_-]//g')
fi

echo ""
echo "📋 配置信息："
echo "   版本号: ${VERSION:-无}"
echo "   自定义文本: ${CUSTOM_TEXT:-无}"
echo "   时间戳: ${TIMESTAMP:-无}"
echo "-------------------------------------"
echo ""

# ==========
# 查找并压缩 xcframework
# ==========
XCFRAMEWORKS=$(find "$ROOT_DIR" -type d -name "*.xcframework" -print | sort)

if [ -z "$XCFRAMEWORKS" ]; then
  echo "ℹ️  未找到任何 xcframework 目录。"
  exit 0
fi

echo "$XCFRAMEWORKS" | while IFS= read -r FRAMEWORK_PATH; do
  FRAMEWORK_NAME="$(basename "$FRAMEWORK_PATH" .xcframework)"
  PARENT_DIR="$(dirname "$FRAMEWORK_PATH")"
  
  # 构建 zip 文件名
  # 顺序：框架名_版本号_自定义文本_时间戳.zip
  ZIP_NAME="${FRAMEWORK_NAME}"
  
  if [ -n "$VERSION" ]; then
    ZIP_NAME="${ZIP_NAME}_${VERSION}"
  fi
  
  if [ -n "$CUSTOM_TEXT" ]; then
    ZIP_NAME="${ZIP_NAME}_${CUSTOM_TEXT}"
  fi
  
  if [ -n "$TIMESTAMP" ]; then
    ZIP_NAME="${ZIP_NAME}_${TIMESTAMP}"
  fi
  
  ZIP_NAME="${ZIP_NAME}.zip"
  ZIP_PATH="${PARENT_DIR}/${ZIP_NAME}"

  echo "📦 ${FRAMEWORK_NAME}.xcframework -> ${ZIP_NAME}"

  if [ -f "$ZIP_PATH" ]; then
    echo "   ⚠️  发现已有 zip，先删除旧文件..."
    rm -f "$ZIP_PATH"
  fi

  # 清理掉可能存在的 macOS 隐藏文件，避免 SwiftPM 解析失败
  find "$FRAMEWORK_PATH" -name ".DS_Store" -delete
  find "$FRAMEWORK_PATH" -name "__MACOSX" -type d -prune -exec rm -rf {} + 2>/dev/null || true

  ditto -c -k --keepParent "$FRAMEWORK_PATH" "$ZIP_PATH"
  echo "   ✅ 压缩完成"
done

echo ""
echo "-------------------------------------"
echo "🎉 所有 xcframework 已完成压缩"

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

XCFRAMEWORKS=$(find "$ROOT_DIR" -type d -name "*.xcframework" -print | sort)

if [ -z "$XCFRAMEWORKS" ]; then
  echo "ℹ️  未找到任何 xcframework 目录。"
  exit 0
fi

echo "$XCFRAMEWORKS" | while IFS= read -r FRAMEWORK_PATH; do
  FRAMEWORK_NAME="$(basename "$FRAMEWORK_PATH")"
  PARENT_DIR="$(dirname "$FRAMEWORK_PATH")"
  ZIP_PATH="${PARENT_DIR}/${FRAMEWORK_NAME}.zip"

  echo "📦 ${FRAMEWORK_NAME} -> ${ZIP_PATH}"

  if [ -f "$ZIP_PATH" ]; then
    echo "   ⚠️  发现已有 zip，先删除旧文件..."
    rm -f "$ZIP_PATH"
  fi

  # 清理掉可能存在的 macOS 隐藏文件，避免 SwiftPM 解析失败
  find "$FRAMEWORK_PATH" -name ".DS_Store" -delete
  find "$FRAMEWORK_PATH" -name "__MACOSX" -type d -prune -exec rm -rf {} +

  ditto -c -k --keepParent "$FRAMEWORK_PATH" "$ZIP_PATH"
  echo "   ✅ 压缩完成"
done

echo "-------------------------------------"
echo "🎉 所有 xcframework 已完成压缩"


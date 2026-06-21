#!/bin/bash
# 非交互式压缩 xcframework，供 SPM 发布流程使用
# 用法: ./zip_xcframeworks_cli.sh --version 2.1.20 [--root-dir .] [--timestamp] [--custom-text fix1]

set -euo pipefail

ROOT_DIR="."
VERSION=""
TIMESTAMP=""
CUSTOM_TEXT=""
USE_TIMESTAMP=true

usage() {
  cat <<'EOF'
用法: zip_xcframeworks_cli.sh --version <版本号> [选项]

选项:
  --version <ver>     版本号（必填，如 2.1.20）
  --root-dir <path>   xcframework 根目录（默认: 当前目录）
  --timestamp         添加时间戳（默认开启）
  --no-timestamp      不添加时间戳
  --custom-text <txt> 自定义后缀（如 fix1、beta）
  -h, --help          显示帮助

输出:
  压缩完成后在 stdout 打印 TIMESTAMP=YYYYMMDDHHMMSS（若启用时间戳）
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --version)
      VERSION="${2:-}"
      shift 2
      ;;
    --root-dir)
      ROOT_DIR="${2:-}"
      shift 2
      ;;
    --timestamp)
      USE_TIMESTAMP=true
      shift
      ;;
    --no-timestamp)
      USE_TIMESTAMP=false
      shift
      ;;
    --custom-text)
      CUSTOM_TEXT="${2:-}"
      shift 2
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      echo "❌ 未知参数: $1"
      usage
      exit 1
      ;;
  esac
done

if [[ -z "$VERSION" ]]; then
  echo "❌ 必须指定 --version"
  usage
  exit 1
fi

if ! command -v ditto >/dev/null 2>&1; then
  echo "❌ 未找到 ditto 命令，请在 macOS 环境下运行此脚本。"
  exit 1
fi

ROOT_DIR="$(cd "$ROOT_DIR" && pwd)"
VERSION="${VERSION// /}"
CUSTOM_TEXT="${CUSTOM_TEXT// /}"
CUSTOM_TEXT=$(echo "$CUSTOM_TEXT" | sed 's/[^a-zA-Z0-9_-]//g')

if [[ "$USE_TIMESTAMP" == true ]]; then
  TIMESTAMP=$(date +"%Y%m%d%H%M%S")
else
  TIMESTAMP=""
fi

echo "🗜️  压缩 ${ROOT_DIR} 下的 xcframework（版本: ${VERSION}）"

XCFRAMEWORKS=$(find "$ROOT_DIR" -maxdepth 1 -type d -name "*.xcframework" -print | sort)

if [[ -z "$XCFRAMEWORKS" ]]; then
  echo "❌ 未找到任何 xcframework 目录"
  exit 1
fi

echo "$XCFRAMEWORKS" | while IFS= read -r FRAMEWORK_PATH; do
  FRAMEWORK_NAME="$(basename "$FRAMEWORK_PATH" .xcframework)"
  PARENT_DIR="$(dirname "$FRAMEWORK_PATH")"

  ZIP_NAME="${FRAMEWORK_NAME}_${VERSION}"
  [[ -n "$CUSTOM_TEXT" ]] && ZIP_NAME="${ZIP_NAME}_${CUSTOM_TEXT}"
  [[ -n "$TIMESTAMP" ]] && ZIP_NAME="${ZIP_NAME}_${TIMESTAMP}"
  ZIP_NAME="${ZIP_NAME}.zip"
  ZIP_PATH="${PARENT_DIR}/${ZIP_NAME}"

  echo "📦 ${FRAMEWORK_NAME}.xcframework -> ${ZIP_NAME}"

  [[ -f "$ZIP_PATH" ]] && rm -f "$ZIP_PATH"

  find "$FRAMEWORK_PATH" -name ".DS_Store" -delete
  find "$FRAMEWORK_PATH" -name "__MACOSX" -type d -prune -exec rm -rf {} + 2>/dev/null || true

  ditto -c -k --keepParent "$FRAMEWORK_PATH" "$ZIP_PATH"
  echo "   ✅ 完成"
done

echo "🎉 所有 xcframework 已压缩"
[[ -n "$TIMESTAMP" ]] && echo "TIMESTAMP=${TIMESTAMP}"

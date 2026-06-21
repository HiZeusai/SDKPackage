#!/bin/bash
# Zeus SPM 全流程发布脚本
# SDKPackage (xcframework -> zip -> tag/release) -> ZSSDK (Package.swift -> checksum -> tag)
#
# 用法:
#   ./publish_spm.sh --version 2.1.20
#   ./publish_spm.sh --version 2.1.20 --frameworks-dir /path/to/xcframeworks
#   ./publish_spm.sh --version 2.1.20 --dry-run

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
SDK_PACKAGE_DIR="${SDK_PACKAGE_DIR:-$SCRIPT_DIR}"
ZSSDK_DIR="${ZSSDK_DIR:-$(dirname "$SCRIPT_DIR")/ZSSDK}"

VERSION=""
FRAMEWORKS_DIR=""
CUSTOM_TEXT=""
USE_TIMESTAMP=true
DRY_RUN=false
SKIP_PUSH=false
COMMIT_MSG=""

GITHUB_RELEASE_REPO="HiZeusai/SDKPackage"
ZSSDK_REPO="HiZeusai/ZSSDK"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

log()  { echo -e "${GREEN}▶${NC} $*"; }
warn() { echo -e "${YELLOW}⚠${NC} $*"; }
err()  { echo -e "${RED}✗${NC} $*" >&2; }

usage() {
  cat <<EOF
用法: publish_spm.sh --version <版本号> [选项]

必填:
  --version <ver>         发布版本号（如 2.1.20），同时作为 git tag

选项:
  --frameworks-dir <dir>  新 xcframework 目录（将其中的 .xcframework 复制到 SDKPackage）
  --custom-text <txt>     zip 文件名自定义后缀
  --no-timestamp          zip 不添加时间戳
  --sdk-package-dir <dir> SDKPackage 本地路径（默认: 脚本所在目录）
  --zssdk-dir <dir>       ZSSDK 本地路径（默认: ../ZSSDK）
  --commit-msg <msg>      git commit 信息（默认: <version> SDK更新）
  --dry-run               只打印步骤，不执行 git push / release
  --skip-push             本地提交和打 tag，但不 push
  -h, --help              显示帮助

示例:
  ./publish_spm.sh --version 2.1.20 --frameworks-dir ~/Downloads/new_frameworks
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --version) VERSION="${2:-}"; shift 2 ;;
    --frameworks-dir) FRAMEWORKS_DIR="${2:-}"; shift 2 ;;
    --custom-text) CUSTOM_TEXT="${2:-}"; shift 2 ;;
    --no-timestamp) USE_TIMESTAMP=false; shift ;;
    --sdk-package-dir) SDK_PACKAGE_DIR="${2:-}"; shift 2 ;;
    --zssdk-dir) ZSSDK_DIR="${2:-}"; shift 2 ;;
    --commit-msg) COMMIT_MSG="${2:-}"; shift 2 ;;
    --dry-run) DRY_RUN=true; shift ;;
    --skip-push) SKIP_PUSH=true; shift ;;
    -h|--help) usage; exit 0 ;;
    *) err "未知参数: $1"; usage; exit 1 ;;
  esac
done

if [[ -z "$VERSION" ]]; then
  err "必须指定 --version"
  usage
  exit 1
fi

COMMIT_MSG="${COMMIT_MSG:-${VERSION} SDK更新}"

run() {
  if [[ "$DRY_RUN" == true ]]; then
    echo "[dry-run] $*"
  else
    "$@"
  fi
}

require_cmd() {
  if ! command -v "$1" >/dev/null 2>&1; then
    err "缺少命令: $1"
    exit 1
  fi
}

require_cmd ditto
require_cmd python3
require_cmd swift
require_cmd git
require_cmd curl

build_zip_name() {
  local name="$1"
  local zip_name="${name}_${VERSION}"
  [[ -n "$CUSTOM_TEXT" ]] && zip_name="${zip_name}_${CUSTOM_TEXT}"
  [[ -n "$TIMESTAMP" ]] && zip_name="${zip_name}_${TIMESTAMP}"
  echo "${zip_name}.zip"
}

collect_zip_files() {
  ZIP_FILES=()
  while IFS= read -r fw; do
    name="$(basename "$fw" .xcframework)"
    ZIP_FILES+=("$SDK_PACKAGE_DIR/$(build_zip_name "$name")")
  done < <(find "$SDK_PACKAGE_DIR" -maxdepth 1 -type d -name "*.xcframework" | sort)
}

# ========== Step 1: 复制 xcframework ==========
if [[ -n "$FRAMEWORKS_DIR" ]]; then
  if [[ ! -d "$FRAMEWORKS_DIR" ]]; then
    err "frameworks 目录不存在: $FRAMEWORKS_DIR"
    exit 1
  fi
  log "复制 xcframework 到 SDKPackage..."
  FRAMEWORKS_DIR="$(cd "$FRAMEWORKS_DIR" && pwd)"
  while IFS= read -r fw; do
    name="$(basename "$fw")"
    log "  $name"
    if [[ "$DRY_RUN" == true ]]; then
      echo "[dry-run] cp -R \"$fw\" \"$SDK_PACKAGE_DIR/$name\""
    else
      rm -rf "$SDK_PACKAGE_DIR/$name"
      cp -R "$fw" "$SDK_PACKAGE_DIR/$name"
    fi
  done < <(find "$FRAMEWORKS_DIR" -maxdepth 1 -type d -name "*.xcframework" | sort)
fi

# ========== Step 2: 压缩 xcframework ==========
log "压缩 xcframework..."
ZIP_ARGS=(--version "$VERSION" --root-dir "$SDK_PACKAGE_DIR")
[[ -n "$CUSTOM_TEXT" ]] && ZIP_ARGS+=(--custom-text "$CUSTOM_TEXT")
[[ "$USE_TIMESTAMP" == false ]] && ZIP_ARGS+=(--no-timestamp)

if [[ "$USE_TIMESTAMP" == true ]]; then
  TIMESTAMP="$(date +"%Y%m%d%H%M%S")"
else
  TIMESTAMP=""
fi

if [[ "$DRY_RUN" == true ]]; then
  echo "[dry-run] bash $SDK_PACKAGE_DIR/zip_xcframeworks_cli.sh ${ZIP_ARGS[*]}"
else
  # 清理旧 zip
  find "$SDK_PACKAGE_DIR" -maxdepth 1 -name "*.zip" -delete 2>/dev/null || true
  ZIP_OUTPUT=$(bash "$SDK_PACKAGE_DIR/zip_xcframeworks_cli.sh" "${ZIP_ARGS[@]}")
  echo "$ZIP_OUTPUT"
  parsed_ts=$(echo "$ZIP_OUTPUT" | grep '^TIMESTAMP=' | cut -d= -f2 || true)
  [[ -n "$parsed_ts" ]] && TIMESTAMP="$parsed_ts"
fi

if [[ "$USE_TIMESTAMP" == true && -z "$TIMESTAMP" ]]; then
  err "未能获取时间戳"
  exit 1
fi

collect_zip_files

# ========== Step 3: SDKPackage git commit + tag ==========
log "SDKPackage: 提交并打 tag ${VERSION}..."
cd "$SDK_PACKAGE_DIR"

run git add -A
if [[ "$DRY_RUN" == true ]]; then
  echo "[dry-run] git commit -m \"$COMMIT_MSG\""
else
  git commit -m "$COMMIT_MSG" || warn "SDKPackage 无新变更可提交"
fi

if git rev-parse "$VERSION" >/dev/null 2>&1; then
  warn "tag $VERSION 已存在，将删除后重建"
  run git tag -d "$VERSION"
  if [[ "$SKIP_PUSH" != true && "$DRY_RUN" != true ]]; then
    git push origin ":refs/tags/$VERSION" 2>/dev/null || true
  fi
fi
run git tag "$VERSION"

if [[ "$SKIP_PUSH" != true ]]; then
  run git push origin main
  run git push origin "$VERSION"
fi

# ========== Step 4: 创建 GitHub Release ==========
log "创建 GitHub Release: $VERSION"

create_release_gh() {
  if ! command -v gh >/dev/null 2>&1; then
    return 1
  fi
  gh release create "$VERSION" \
    --repo "$GITHUB_RELEASE_REPO" \
    --title "$VERSION" \
    --notes "Release $VERSION" \
    "${ZIP_FILES[@]}"
}

create_release_api() {
  if [[ -z "${GITHUB_TOKEN:-}" ]]; then
    return 1
  fi
  local response upload_url
  response=$(curl -s -X POST \
    -H "Authorization: token $GITHUB_TOKEN" \
    -H "Accept: application/vnd.github+json" \
    "https://api.github.com/repos/$GITHUB_RELEASE_REPO/releases" \
    -d "{\"tag_name\":\"$VERSION\",\"name\":\"$VERSION\",\"body\":\"Release $VERSION\"}")
  upload_url=$(echo "$response" | python3 -c "import sys,json; d=json.load(sys.stdin); print(d.get('upload_url','').split('{')[0])" 2>/dev/null || true)
  if [[ -z "$upload_url" ]]; then
    upload_url=$(curl -s \
      -H "Authorization: token $GITHUB_TOKEN" \
      "https://api.github.com/repos/$GITHUB_RELEASE_REPO/releases/tags/$VERSION" \
      | python3 -c "import sys,json; d=json.load(sys.stdin); print(d.get('upload_url','').split('{')[0])" 2>/dev/null || true)
  fi
  [[ -z "$upload_url" ]] && return 1
  for zip in "${ZIP_FILES[@]}"; do
    local basename
    basename=$(basename "$zip")
    log "  上传 $basename"
    curl -s -X POST \
      -H "Authorization: token $GITHUB_TOKEN" \
      -H "Content-Type: application/zip" \
      --data-binary @"$zip" \
      "${upload_url}?name=${basename}" >/dev/null
  done
  return 0
}

if [[ "$DRY_RUN" == true ]]; then
  echo "[dry-run] 创建 Release ${VERSION}，上传 ${#ZIP_FILES[@]} 个 zip"
elif create_release_gh; then
  log "Release 已通过 gh 创建"
elif create_release_api; then
  log "Release 已通过 GitHub API 创建"
else
  warn "未能自动创建 Release。请手动操作："
  echo "  1. 打开 https://github.com/$GITHUB_RELEASE_REPO/releases/new?tag=$VERSION"
  echo "  2. 上传以下 zip 文件:"
  for zip in "${ZIP_FILES[@]}"; do
    echo "     - $(basename "$zip")"
  done
  echo ""
  read -p "Release 创建完成后按 Enter 继续..."
fi

log "SDKPackage 下载地址:"
for zip in "${ZIP_FILES[@]}"; do
  basename=$(basename "$zip")
  echo "  https://github.com/$GITHUB_RELEASE_REPO/releases/download/$VERSION/$basename"
done

# ========== Step 5: 更新 ZSSDK Package.swift ==========
log "更新 ZSSDK Package.swift..."
cd "$ZSSDK_DIR"

URL_ARGS=(--version "$VERSION" --timestamp "$TIMESTAMP")
[[ -n "$CUSTOM_TEXT" ]] && URL_ARGS+=(--custom-text "$CUSTOM_TEXT")

if [[ "$DRY_RUN" == true ]]; then
  echo "[dry-run] bash update_package_urls.sh ${URL_ARGS[*]}"
else
  bash "$ZSSDK_DIR/update_package_urls.sh" "${URL_ARGS[@]}"
fi

# ========== Step 6: 更新 checksum ==========
log "计算并更新 checksum..."
if [[ "$DRY_RUN" == true ]]; then
  echo "[dry-run] bash update_checksum.sh"
else
  RETRY=0
  until bash "$ZSSDK_DIR/update_checksum.sh"; do
    RETRY=$((RETRY + 1))
    if [[ $RETRY -ge 6 ]]; then
      err "checksum 更新失败（已重试 5 次）"
      exit 1
    fi
    warn "下载失败，30 秒后重试 ($RETRY/5)..."
    sleep 30
  done
fi

# ========== Step 7: 校验 Package.swift ==========
log "校验 swift package resolve..."
if [[ "$DRY_RUN" == true ]]; then
  echo "[dry-run] swift package resolve"
else
  rm -rf .build
  if ! swift package resolve 2>&1; then
    err "Package.swift 校验失败！请检查 URL 和 checksum"
    exit 1
  fi
  log "Package.swift 校验通过"
fi

# ========== Step 8: ZSSDK commit + tag ==========
log "ZSSDK: 提交并打 tag ${VERSION}..."
run git add Package.swift
if [[ "$DRY_RUN" == true ]]; then
  echo "[dry-run] git commit -m \"$COMMIT_MSG\""
else
  git commit -m "$COMMIT_MSG" || warn "ZSSDK 无新变更可提交"
fi

if git rev-parse "$VERSION" >/dev/null 2>&1; then
  warn "tag $VERSION 已存在，将删除后重建"
  run git tag -d "$VERSION"
  if [[ "$SKIP_PUSH" != true && "$DRY_RUN" != true ]]; then
    git push origin ":refs/tags/$VERSION" 2>/dev/null || true
  fi
fi
run git tag "$VERSION"

if [[ "$SKIP_PUSH" != true ]]; then
  run git push origin main
  run git push origin "$VERSION"
fi

echo ""
echo "========================================="
echo -e "${GREEN}SPM 发布完成: $VERSION${NC}"
echo "========================================="
echo "SDKPackage: https://github.com/$GITHUB_RELEASE_REPO/releases/tag/$VERSION"
echo "ZSSDK:      https://github.com/$ZSSDK_REPO/releases/tag/$VERSION"
echo ""
echo "集成方式:"
echo "  .package(url: \"https://github.com/$ZSSDK_REPO.git\", exact: \"$VERSION\")"

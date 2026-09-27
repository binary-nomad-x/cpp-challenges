#!/usr/bin/env bash
# Remove every generated executable from the repository.
#   - everything inside build/run/
#   - stray *.exe anywhere in the source tree
#   - stray a.out and same-named extension-less binaries next to a .cpp
# Source files are never touched. Safe to run at any time, including while a
# previously built program is still running (the inode is unlinked, not killed).

set -euo pipefail

ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
OUT_DIR="$ROOT/build/run"

PRUNE_DIRS=( -name .git -o -name build -o -name node_modules -o -name cmake-build-debug -o -name .idea -o -name .vscode )

count=0
skipped=0

# Executables that are mapped by a live process right now. Removing one of
# those would break an active run or a gdb session, so they are left alone.
RUNNING_LIST="$(mktemp)"
trap 'rm -f "$RUNNING_LIST"' EXIT
for link in /proc/[0-9]*/exe; do
  [ -e "$link" ] || continue
  target="$(readlink -- "$link" 2>/dev/null || true)"
  [ -n "$target" ] && printf '%s\n' "${target% (deleted)}" >>"$RUNNING_LIST"
done

is_running() {
  [ -s "$RUNNING_LIST" ] || return 1
  grep -qxF -- "$1" "$RUNNING_LIST"
}

report() {
  [ -f "$1" ] || return 0
  if is_running "$1"; then
    skipped=$((skipped + 1))
    printf 'kept (in use): %s\n' "${1#"$ROOT"/}"
    return 0
  fi
  rm -f -- "$1"
  count=$((count + 1))
  printf 'removed: %s\n' "${1#"$ROOT"/}"
}

# 1. Executables produced by scripts/run-cpp.sh
if [ -d "$OUT_DIR" ]; then
  while IFS= read -r -d '' f; do
    [ -f "$f" ] || continue
    report "$f"
  done < <(find "$OUT_DIR" -maxdepth 1 -type f -print0)
fi

# 2. Windows-style executables anywhere in the tree
while IFS= read -r -d '' f; do
  [ -f "$f" ] || continue
  report "$f"
done < <(find "$ROOT" \( "${PRUNE_DIRS[@]}" \) -prune -o -type f -name '*.exe' -print0)

# 3. Default GCC output name
while IFS= read -r -d '' f; do
  [ -f "$f" ] || continue
  report "$f"
done < <(find "$ROOT" \( "${PRUNE_DIRS[@]}" \) -prune -o -type f -name 'a.out' -print0)

# 4. Extension-less binaries sitting beside their own source file
#    (e.g. the old `g++ -o solution solution.cpp` habit)
while IFS= read -r -d '' src; do
  dir="$(dirname -- "$src")"
  base="$(basename -- "$src")"
  stem="${base%.*}"
  for cand in "$dir/$stem"; do
    [ -f "$cand" ] || continue
    case "$cand" in *.cpp|*.cc|*.cxx|*.C) continue ;; esac
    [ -x "$cand" ] || continue
    report "$cand"
  done
done < <(find "$ROOT" \( "${PRUNE_DIRS[@]}" \) -prune -o -type f \( -name '*.cpp' -o -name '*.cc' -o -name '*.cxx' \) -print0)

# Drop build/run if it ended up empty, but keep build/ (it is a CMake dir).
rmdir "$OUT_DIR" 2>/dev/null || true

if [ "$count" -eq 0 ] && [ "$skipped" -eq 0 ]; then
  echo "clean: nothing to remove"
else
  echo "clean: removed $count executable(s), kept $skipped in use"
fi

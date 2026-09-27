#!/usr/bin/env bash
# Compile a .cpp into build/run/, run it, then remove the executable.
# Never writes an executable next to the source file.
#
# Usage:
#   scripts/run-cpp.sh <file.cpp> [program args...]   compile, run, auto-delete exe
#   scripts/run-cpp.sh -k <file.cpp> [args...]       keep the exe (for gdb)
#   scripts/run-cpp.sh -b <file.cpp>                 compile only, keep exe
#   scripts/run-cpp.sh -d <file.cpp>                 compile with -O0 -g, keep exe
#   scripts/run-cpp.sh -c                            clean build/run and stray exes
#   scripts/run-cpp.sh -o NAME <file.cpp>            force the executable name
#   scripts/run-cpp.sh -h                            help
#
# Env: CXX (default g++), CXXSTD (default c++17), CXXFLAGS (extra flags)

set -euo pipefail

ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
OUT_DIR="$ROOT/build/run"
CLEANER="$ROOT/scripts/clean-exes.sh"
STALE_MINUTES="${STALE_MINUTES:-120}"

CXX_BIN="${CXX:-}"
if [ -z "$CXX_BIN" ]; then
  if command -v g++ >/dev/null 2>&1; then
    CXX_BIN="g++"
  elif command -v g++-13 >/dev/null 2>&1; then
    CXX_BIN="g++-13"
  elif command -v clang++ >/dev/null 2>&1; then
    CXX_BIN="clang++"
  else
    echo "run-cpp: no C++ compiler found (set CXX)" >&2
    exit 127
  fi
fi

usage() { awk 'NR>1 && /^#/ { sub(/^# ?/, ""); print; next } NR>1 { exit }' "${BASH_SOURCE[0]}"; }

# An executable that a live process still has mapped is never pruned.
is_in_use() {
  local link target
  for link in /proc/[0-9]*/exe; do
    [ -e "$link" ] || continue
    target="$(readlink -- "$link" 2>/dev/null || true)"
    [ "$target" = "$1" ] && return 0
  done
  return 1
}

prune_stale() {
  [ -d "$OUT_DIR" ] || return 0
  local f
  while IFS= read -r -d '' f; do
    is_in_use "$f" && continue
    rm -f -- "$f"
  done < <(find "$OUT_DIR" -maxdepth 1 -type f -mmin "+$STALE_MINUTES" -print0 2>/dev/null)
  return 0
}

die() { echo "run-cpp: $*" >&2; exit 1; }

KEEP=0
BUILD_ONLY=0
DEBUG=0
FORCE_NAME=""

while getopts ":kbdco:h" opt; do
  case "$opt" in
    k) KEEP=1 ;;
    b) BUILD_ONLY=1 ;;
    d) KEEP=1; DEBUG=1 ;;
    c) exec "$CLEANER" ;;
    o) FORCE_NAME="$OPTARG" ;;
    h) usage; exit 0 ;;
    \?) die "unknown option -$OPTARG" ;;
    :) die "option -$OPTARG needs an argument" ;;
  esac
done
shift $((OPTIND - 1))

[ $# -ge 1 ] || { usage; exit 2; }

SRC="$1"
shift
[ -f "$SRC" ] || die "no such file: $SRC"
case "$SRC" in
  *.cpp|*.cc|*.cxx|*.C) ;;
  *) die "not a C++ source file: $SRC" ;;
esac

SRC_ABS="$(cd -- "$(dirname -- "$SRC")" && pwd)/$(basename -- "$SRC")"
SRC_DIR="$(dirname -- "$SRC_ABS")"

mkdir -p "$OUT_DIR"
prune_stale

NAME="$(basename -- "$SRC_ABS")"
BASE_STEM="${NAME%.*}"
# Disambiguate same-named files in different exercise folders.
REL_DIR="${SRC_DIR#"$ROOT"/}"
if [ "$REL_DIR" = "$SRC_DIR" ]; then
  STEM="root-$BASE_STEM"
else
  STEM="$(printf '%s' "$REL_DIR" | tr '/' '-' | sed 's/[^A-Za-z0-9._-]/-/g')-$BASE_STEM"
fi
[ -n "$FORCE_NAME" ] && STEM="$FORCE_NAME"
EXE="$OUT_DIR/$STEM"

# Sweep any executable an older workflow left beside this source file.
rm -f "$SRC_DIR/$BASE_STEM" "$SRC_DIR/$BASE_STEM.exe" "$SRC_DIR/a.out" 2>/dev/null || true

if [ "$DEBUG" -eq 1 ]; then
  OPT_FLAGS=(-O0 -g3)
else
  OPT_FLAGS=(-g)
fi

# Reuse an up-to-date executable instead of recompiling (only when we keep it).
NEED_BUILD=1
if [ "$KEEP" -eq 1 ] && [ -x "$EXE" ] && [ "$EXE" -nt "$SRC_ABS" ]; then
  NEED_BUILD=0
fi

if [ "$NEED_BUILD" -eq 1 ]; then
  # shellcheck disable=SC2086
  "$CXX_BIN" "-std=${CXXSTD:-c++17}" "${OPT_FLAGS[@]}" ${CXXFLAGS:-} \
    "$SRC_ABS" -o "$EXE"
fi

if [ "$BUILD_ONLY" -eq 1 ]; then
  echo "built: $EXE"
  exit 0
fi

cleanup() { [ "$KEEP" -eq 1 ] || rm -f "$EXE"; }
trap cleanup EXIT INT TERM HUP

# Run from the source directory so relative input files still resolve.
cd -- "$SRC_DIR"
set +e
"$EXE" "$@"
STATUS=$?
set -e

exit "$STATUS"

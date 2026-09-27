# C++ workspace rules

## Build & run — always use the scripts

Never compile a `.cpp` with a bare `g++`/`clang++` command, and never let an
executable land next to a source file.

```sh
scripts/run-cpp.sh <file.cpp> [args...]   # compile -> build/run/ -> run -> delete exe
scripts/run-cpp.sh -b <file.cpp>         # compile only, keep exe
scripts/run-cpp.sh -k <file.cpp>         # run, but keep the exe (for gdb)
scripts/run-cpp.sh -d <file.cpp>         # -O0 -g build, keep exe
scripts/run-cpp.sh -c                    # purge build/run + stray exes
```

Rules:

1. All executables live in `build/run/` (already git-ignored). Source folders
   (`basics/`, `exercises/`, `kirch-prinz/`, repo root) hold `.cpp` files only.
2. The default mode deletes the executable as soon as the program exits, via an
   `EXIT`/`INT`/`TERM` trap, so an interrupted run cleans up too.
3. `scripts/clean-exes.sh` sweeps `build/run/`, stray `*.exe`, `a.out`, and
   same-named binaries next to a `.cpp`. It never deletes source files and never
   deletes an executable that a live process is currently running.
4. The opencode plugin `.opencode/plugin/exe-guard.ts` rewrites ad-hoc compiler
   invocations to output into `build/run/`, and runs the cleaner when a session
   goes idle or is deleted. It is a safety net, not a replacement for the
   scripts.
5. Whole-project builds still go through CMake: `cmake --build build`. Its
   output also stays inside `build/`.

## Before finishing a task

Run `scripts/clean-exes.sh` and confirm no executable is left in a source
directory.

# C++ for Competitive Programming & Systems

**Goal:** Take an unfamiliar problem, derive an efficient algorithm, prove it, and implement it under time pressure.

---

## Project Setup

### Layout

```text
learning-cpp/
├── CMakeLists.txt
├── main.cpp            # optional, builds main_app
├── basics/             # syntax, types, IO, functions
├── exercises/          # problem solutions, grouped by topic
│   ├── dp/
│   ├── graphs/
│   └── ...
├── kirch-prinz/        # book exercises
└── .vscode/
    └── settings.json   # shared settings only
```

### How the build works

- Every `.cpp` under the project becomes its own executable.
- The target name comes from the path: `exercises/dp/knapsack.cpp` → `exercises-dp-knapsack`.
- Binaries go to `build/bin/`.
- Build folders are ignored by CMake and git: `build/` (VS Code) and `cmake-build-*/` (CLion).

### Adding a new file

1. Create the `.cpp` in any subfolder.
2. Reload the project:
    - CLion: **Reload CMake Project**
    - VS Code: **CMake: Configure**
3. Pick the target from the status bar and run it.

### VS Code setup (once per machine)

1. Install **C/C++**, **CMake Tools**, and **CMake**.
2. `Ctrl+Shift+P` → **CMake: Select a Kit** → choose the same compiler CLion uses.
3. Select the build target from the status bar.
4. Press `F5` to run or debug.

Keep only `settings.json` in `.vscode/`. Do not commit `tasks.json`, `launch.json`, or `c_cpp_properties.json`, because
CMake Tools handles them.

### Rules for consistency

- Use the same toolchain in CLion and VS Code.
- Do not hardcode compiler paths in the repo.
- Name files by topic, so each target name is clear.

---

## Learning Path

| #  | Phase                    | Focus                                                                  |
|----|--------------------------|------------------------------------------------------------------------|
| 1  | C++ basics               | types, `long long`, IO, loops, functions, references, `struct`         |
| 2  | STL                      | `vector`, `pair`, `set`, `map`, `stack`, `queue`, `priority_queue`     |
| 3  | STL algorithms           | `sort` with comparators, `lower_bound`, `upper_bound`, `accumulate`    |
| 4  | Complexity               | read constraints, estimate what runs in time                           |
| 5  | Core techniques          | prefix sums, two pointers, sliding window, binary search on answer     |
| 6  | Recursion & backtracking | subsets, permutations, grids, N-Queens                                 |
| 7  | Trees & graphs           | DFS, BFS, Dijkstra, DSU, MST                                           |
| 8  | Greedy                   | sorting, intervals, priority-queue greedy, exchange arguments          |
| 9  | Dynamic programming      | 1D, 2D, knapsack, coin change, LIS, LCS, then tree/bitmask DP          |
| 10 | Number theory            | gcd, sieve, modular arithmetic, fast power                             |
| 11 | Advanced structures      | Fenwick tree, segment tree, lazy propagation, trie, sparse table       |
| 12 | Advanced algorithms      | SCC, bridges, KMP, Z-algorithm, suffix arrays (learn only when needed) |

---

## Complexity Cheat Sheet

| n       | Allowed complexity |
|---------|--------------------|
| ≤ 20    | O(2ⁿ), O(n!)       |
| ≤ 500   | O(n³)              |
| ≤ 5,000 | O(n²)              |
| ≤ 10⁶   | O(n log n)         |
| ≤ 10⁸   | O(n)               |

---

## Pattern Recognition

| Signal                    | Technique                   |
|---------------------------|-----------------------------|
| Sorted data               | Binary search, two pointers |
| Repeated range sums       | Prefix sums                 |
| Contiguous subarray       | Sliding window              |
| Shortest path, unweighted | BFS                         |
| Shortest path, weighted   | Dijkstra                    |
| Connectivity              | DFS, BFS, DSU               |
| Overlapping subproblems   | DP                          |
| Range query + update      | Fenwick, segment tree       |
| Prefix matching           | Trie                        |

---

## Problem-Solving Method

1. Read the input, output, constraints, and examples.
2. Use the constraints to decide the target complexity.
3. Solve the examples by hand.
4. Write a brute force first.
5. Find the bottleneck and match a pattern.
6. Check the complexity before coding.
7. Implement cleanly, then test edge cases: min, max, duplicates, empty input, overflow.

---

## Contest Strategy

- **During:** solve easy problems first, return to hard ones only with a clear idea.
- **After:** read the editorial, close it, reimplement the solution from memory, then submit. If you can't reimplement
  it, you haven't learned it.

---

## Debugging

On Wrong Answer: find the smallest failing case, compare expected and actual output, identify the wrong assumption, fix
it, and retest.

Common causes:

- Integer overflow (use `long long`)
- Off-by-one errors (`i < n` vs `i <= n`)
- Wrong binary search bounds
- Missing initialization in DP, BFS, or Dijkstra
- Missing `visited` array
- Forgetting multiple test cases

---

## Weekly Plan (about 2 hours per day)

| Day      | Focus                                     |
|----------|-------------------------------------------|
| Mon–Fri  | 30 min learn, 60 min solve, 30 min review |
| Saturday | Virtual contest                           |
| Sunday   | Re-solve old problems, update notes       |

Track quality, not just count: solved alone, with hints, or with the editorial.

---

## Resources

| Resource         | Link                              |
|------------------|-----------------------------------|
| CSES Problem Set | https://cses.fi/problemset/       |
| Codeforces       | https://codeforces.com/problemset |
| AtCoder          | https://atcoder.jp                |
| USACO Guide      | https://usaco.guide               |
| C++ Reference    | https://en.cppreference.com       |

---

**Philosophy:** Master about 10 core techniques and their variations. That beats shallow exposure to everything.
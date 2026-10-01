# ⚡ C++ for Competitive Programming & Systems — 2026 Roadmap

A focused path from C++ fundamentals → CP mastery → systems-level depth.

**Goal:** Become a programmer who can look at an unfamiliar problem, derive an efficient algorithm, prove it to yourself, and implement it reliably under time pressure.

---

## 🧭 Learning Paths

```text
┌─────────────────────────────────────────────────────────────┐
│  1. C++ Fundamentals      → syntax, types, IO, functions    │
│  2. STL Mastery           → vector, map, set, priority_q    │
│  3. Algorithms            → sorting, searching, complexity  │
│  4. Core Techniques       → two pointers, sliding window,   │
│                             prefix sum, binary search       │
│  5. Recursion & BT        → subsets, permutations, grids    │
│  6. Data Structures       → trees, graphs, heaps, DSU       │
│  7. DP                    → 1D, 2D, knapsack, LIS, LCS      │
│  8. Number Theory         → sieve, modular arithmetic       │
│  9. Advanced Structures   → Fenwick, Segment Tree, Trie     │
│ 10. Advanced Algorithms   → SCC, KMP, Z, suffix arrays      │
└─────────────────────────────────────────────────────────────┘
```

---

## 📚 Phase Breakdown

### Phase 1 — C++ Fundamentals

**Learn:** variables, `long long`, IO (`cin`/`cout`, `sync_with_stdio`), operators, conditions, loops, functions (by ref, `const&`), arrays, strings, `auto`, `struct`, `enum`.
**Skip for now:** advanced OOP, inheritance, templates, GUI, multithreading.

---

### Phase 2 — STL Fundamentals

**Must know:** `vector`, `pair`, `set`, `multiset`, `map`, `unordered_map`, `stack`, `queue`, `deque`, `priority_queue`, iterators.

---

### Phase 3 — STL Algorithms

**Must know:** `sort`, `reverse`, `min`/`max`, `swap`, `binary_search`, `lower_bound`, `upper_bound`, `min_element`, `max_element`, `accumulate`, `count`, `find`.

Custom comparators + sorting pairs/structs are **mandatory**.

---

### Phase 4 — Complexity Analysis

**Know:** O(1), O(log n), O(n), O(n log n), O(n²), O(2ⁿ), O(n!).

**Habit:** Read constraints → estimate allowed complexity → design algorithm.

| n      | Allowed complexity |
| ------ | ------------------ |
| ≤ 20   | O(2ⁿ) / O(n!)      |
| ≤ 500  | O(n³)              |
| ≤ 5000 | O(n²)              |
| ≤ 10⁶  | O(n log n)         |
| ≤ 10⁸  | O(n)               |

---

### Phase 5 — Core Techniques

- Prefix sum
- Frequency counting (array vs map)
- Sorting-based solving
- **Two pointers**
- **Sliding window**
- **Binary search on answer**

---

### Phase 6 — Recursion & Backtracking

Base case → recursive case → call stack.
Practice: subsets, permutations, combinations, grid search, N-Queens.

Structure:

```text
Choose → Explore → Undo → Try next
```

---

### Phase 7 — Data Structures

**Conceptual:** arrays, dynamic arrays, linked lists, stacks, queues, hash tables, heaps.
**Then:** binary trees, DFS/BFS traversals, BST, tree DFS pattern.

---

### Phase 8 — Graphs

- Adjacency list (default in CP)
- **BFS** — shortest path (unweighted), components, multi-source
- **DFS** — components, cycles, topological sort
- **Dijkstra** — weighted shortest path
- **DSU / Union-Find** — dynamic connectivity
- **MST** — Kruskal (DSU), Prim (heap)

---

### Phase 9 — Greedy

Sorting + greedy, interval scheduling, priority-queue greedy, exchange arguments.

The skill is _recognizing_ when greedy works — not memorizing algorithms.

---

### Phase 10 — Dynamic Programming

Order matters:

1. **1D DP** — Fibonacci, Climbing Stairs, House Robber
2. **2D DP** — grid paths, knapsack
3. **0/1 & Unbounded Knapsack**
4. **Coin Change** (min coins / count ways)
5. **LIS** — O(n²) then O(n log n)
6. **LCS** — string 2D DP
7. **Advanced** — Tree DP, Bitmask DP, Digit DP, Interval DP

---

### Phase 11 — Number Theory

GCD, LCM, primality, **Sieve of Eratosthenes**, factorization, modular arithmetic, **binary exponentiation**.
Later: modular inverse, Fermat, Euler Totient, CRT, extended Euclid.

---

### Phase 12 — Advanced Data Structures

- **Fenwick Tree (BIT)** — point update, prefix query
- **Segment Tree** — range query + update
- **Lazy Propagation**
- **Sparse Table** — static RMQ
- **Trie** — prefix / XOR problems

---

### Phase 13 — Advanced Algorithms

- Floyd-Warshall, Bellman-Ford
- SCC (Kosaraju, Tarjan)
- Bridges, articulation points
- KMP, Z-algorithm
- Rolling hash, suffix array
- Advanced DP optimizations (CHT, D&C)

Only learn when problem difficulty justifies.

---

## 🧠 Problem-Solving Method

```text
1. Read carefully   → input, output, constraints, examples
2. Study constraints → what complexity fits?
3. Solve examples    → manually, understand "why"
4. Brute force       → write it, even if slow
5. Find bottleneck   → what makes it slow?
6. Match pattern     → see table below
7. Compute complexity before coding
8. Implement cleanly
9. Test edge cases   → min, max, duplicates, empty, overflow
10. Submit & analyze
```

### Pattern Recognition Table

| Signal                     | Technique                    |
| -------------------------- | ---------------------------- |
| Sorted data                | Binary Search / Two Pointers |
| Repeated range sums        | Prefix Sum                   |
| Contiguous subarray        | Sliding Window               |
| Frequency                  | Map / Array                  |
| Shortest path (unweighted) | BFS                          |
| Shortest path (weighted)   | Dijkstra                     |
| Connectivity               | DFS / BFS / DSU              |
| Overlapping subproblems    | DP                           |
| Range query / update       | Fenwick / Segment Tree       |
| Prefix strings             | Trie                         |

---

## 🏆 Contest Strategy

**During:**
Read all → solve easy first → medium → hard → return only with a clear idea.

**After (critical):**
For every unsolved problem:

```text
Read editorial → understand → CLOSE it → reimplement → submit
```

If you can't reimplement, you didn't learn it.

---

## 🐛 Debugging

On Wrong Answer:

```text
Smallest failing case → expected vs actual → wrong assumption → fix → retest
```

**Common causes:**

- Integer overflow → use `long long`
- Off-by-one → `i < n` vs `i <= n`
- Binary search invariants
- DP/BFS/Dijkstra initialization
- Forgetting multiple test cases (`t`)
- Missing `visited` array

---

## 📅 Weekly Plan (2 hrs/day)

| Day      | Focus                                       |
| -------- | ------------------------------------------- |
| Mon–Fri  | 30 min learn · 60 min solve · 30 min review |
| Saturday | Contest or virtual contest                  |
| Sunday   | Review editorials, re-solve, notes          |

---

## 📈 Progression

Track **quality**, not just quantity:

- Solved independently vs. with hints vs. with editorial
- Contest rating trend
- Recurring mistakes
- Topics mastered

Difficulty ladder: `800 → 1000 → 1200 → 1400 → 1600+`

The real progression:

```text
Can implement → Can recognize pattern → Can derive solution
→ Can solve unfamiliar variations → Can solve under time pressure
```

---

## 🗂 Repo Layout

```text
cpp-cp/
├── 01-basics/
├── 02-stl/
├── 03-algorithms/
├── 04-complexity/
├── 05-techniques/      # prefix sum, two pointers, sliding window
├── 06-recursion/
├── 07-data-structures/
├── 08-trees/
├── 09-graphs/
├── 10-greedy/
├── 11-dp/
├── 12-number-theory/
├── 13-advanced-ds/     # fenwick, seg tree, trie
└── 14-advanced-algos/  # SCC, KMP, suffix arrays
```

---

## ✅ Master Checklist (Condensed)

- [ ] **C++** — types, IO, loops, functions, references, structs
- [ ] **STL** — vector, pair, set, map, stack, queue, pq
- [ ] **Algos** — sort, binary_search, lower/upper_bound
- [ ] **Complexity** — O(1) → O(n!)
- [ ] **Techniques** — prefix sum, two pointers, sliding window
- [ ] **Recursion** — subsets, permutations, backtracking
- [ ] **Trees** — DFS, BFS, BST
- [ ] **Graphs** — BFS, DFS, Dijkstra, DSU, MST
- [ ] **Greedy** — sorting, intervals, priority queue
- [ ] **DP** — 1D, 2D, knapsack, LIS, LCS, tree DP, bitmask
- [ ] **Number Theory** — sieve, mod arithmetic, fast pow
- [ ] **Advanced DS** — Fenwick, Seg Tree, Trie, Sparse Table
- [ ] **Advanced Algos** — SCC, KMP, Z, suffix array

---

## 🎯 Philosophy

Don't memorize 100 algorithms.

Deeply master **10 techniques** and solve many variations of each — that beats shallow exposure to everything.

Final progression:

```text
Learn → Practice → Fail → Analyze → Recognize patterns → Solve faster → Compete
```

**Primary goal:** _Take an unfamiliar problem, derive an efficient algorithm, prove it, and implement it under pressure._

---

## 🔗 External Resources (Optional)

| Resource         | Link                              |
| ---------------- | --------------------------------- |
| CSES Problem Set | https://cses.fi/problemset/       |
| Codeforces       | https://codeforces.com/problemset |
| LeetCode         | https://leetcode.com              |
| AtCoder          | https://atcoder.jp                |
| USACO Guide      | https://usaco.guide               |
| C++ Reference    | https://en.cppreference.com       |

---

### 🧰 Local Tooling

```sh
./scripts/run-cpp.sh exercises/XX-name/solution.cpp   # compile & run (temp binary)
./scripts/clean-exes.sh                               # cleanup stray binaries
```

## Exercises in this repo

| #  | Challenge                         | Difficulty | Technique      |
|:---|:----------------------------------|:-----------|:---------------|
| 01 | Smallest Missing Positive Integer | Medium     | Cyclic Sort    |
| 02 | Two Sum                           | Easy       | Hash Map       |
| 03 | FizzBuzz                          | Easy       | Conditionals   |
| 04 | Valid Parentheses                 | Medium     | Stack          |
| 05 | Longest Substring Without Repeats | Medium     | Sliding Window |
| 06 | Container With Most Water         | Medium     | Two Pointers   |
| 07 | Trapping Rain Water               | Hard       | Two Pointers   |

Compile & run any exercise:

```sh
cd exercises/XX-name && g++ -std=c++17 -o solution solution.cpp && ./solution
```

---

## More practice resources

| Resource             | Link                                                     | Focus                      |
|:---------------------|:---------------------------------------------------------|:---------------------------|
| w3resource (basic)   | https://www.w3resource.com/cpp-exercises/                | C++ fundamentals           |
| w3resource (current) | https://www.w3resource.com/cpp-exercises/basic/index.php | Basic exercises            |
| CSES Problem Set     | https://cses.fi/problemset/                              | DSA (comprehensive)        |
| Codeforces           | https://codeforces.com/problemset                        | Competitive programming    |
| LeetCode             | https://leetcode.com                                     | Interview prep             |
| AtCoder              | https://atcoder.jp                                       | Beginner-friendly contests |
| HackerRank           | https://www.hackerrank.com/domains/cpp                   | C++ domain challenges      |
| USACO Guide          | https://usaco.guide                                      | Olympiad training          |
| CodeChef             | https://www.codechef.com                                 | Monthly contests           |
| C++ Reference        | https://en.cppreference.com                              | Language reference         |

```ssh
Remove-Item -Path .\* -Include *.exe -Recurse
```



Below is a project-ready `README.md`/roadmap document. It is written as a long-term **C++ Competitive Programming curriculum for 2026**, while keeping software-engineering C++ topics separate from CP-specific material.

# C++ Competitive Programming Roadmap — 2026

A structured roadmap for learning **C++ specifically for Competitive Programming (CP)**, progressing from programming fundamentals to advanced algorithms and data structures.

The goal is not to learn every feature of C++. The goal is to become highly effective at:

* Understanding programming problems
* Designing algorithms
* Analyzing time and space complexity
* Implementing solutions quickly and correctly
* Recognizing common problem-solving patterns
* Using C++ STL efficiently
* Solving increasingly difficult competitive programming problems

---

## Table of Contents

1. [Roadmap Overview](#1-roadmap-overview)
2. [Phase 0 — Environment Setup](#2-phase-0--environment-setup)
3. [Phase 1 — C++ Fundamentals](#3-phase-1--c-fundamentals)
4. [Phase 2 — STL Fundamentals](#4-phase-2--stl-fundamentals)
5. [Phase 3 — STL Algorithms](#5-phase-3--stl-algorithms)
6. [Phase 4 — Complexity Analysis](#6-phase-4--complexity-analysis)
7. [Phase 5 — Basic Problem Solving](#7-phase-5--basic-problem-solving)
8. [Phase 6 — Searching and Binary Search](#8-phase-6--searching-and-binary-search)
9. [Phase 7 — Recursion and Backtracking](#9-phase-7--recursion-and-backtracking)
10. [Phase 8 — Fundamental Data Structures](#10-phase-8--fundamental-data-structures)
11. [Phase 9 — Trees](#11-phase-9--trees)
12. [Phase 10 — Graphs](#12-phase-10--graphs)
13. [Phase 11 — Greedy Algorithms](#13-phase-11--greedy-algorithms)
14. [Phase 12 — Dynamic Programming](#14-phase-12--dynamic-programming)
15. [Phase 13 — Number Theory](#15-phase-13--number-theory)
16. [Phase 14 — Advanced Data Structures](#16-phase-14--advanced-data-structures)
17. [Phase 15 — Advanced Algorithms](#17-phase-15--advanced-algorithms)
18. [Problem-Solving Methodology](#18-problem-solving-methodology)
19. [Contest Strategy](#19-contest-strategy)
20. [Debugging Strategy](#20-debugging-strategy)
21. [What NOT to Learn Initially](#21-what-not-to-learn-initially)
22. [Recommended Weekly Schedule](#22-recommended-weekly-schedule)
23. [Progression System](#23-progression-system)
24. [Project Structure](#24-project-structure)
25. [Master Checklist](#25-master-checklist)

---

# 1. Roadmap Overview

The complete learning progression is:

```text
C++ Fundamentals
        ↓
Arrays & Strings
        ↓
STL
        ↓
Sorting & Searching
        ↓
Complexity Analysis
        ↓
Basic Problem Solving
        ↓
Prefix Sum
        ↓
Two Pointers
        ↓
Sliding Window
        ↓
Binary Search
        ↓
Recursion
        ↓
Backtracking
        ↓
Basic Data Structures
        ↓
Trees
        ↓
Graphs
        ↓
Greedy Algorithms
        ↓
Dynamic Programming
        ↓
Number Theory
        ↓
DSU
        ↓
Shortest Paths
        ↓
Fenwick Tree
        ↓
Segment Tree
        ↓
Advanced Graph Algorithms
        ↓
Advanced String Algorithms
        ↓
Advanced Dynamic Programming
```

Do not attempt to learn everything at once.

Competitive programming is best learned incrementally:

```text
Learn concept
    ↓
Solve easy problems
    ↓
Solve variations
    ↓
Solve unfamiliar problems
    ↓
Review mistakes
    ↓
Repeat
```

---

# 2. Phase 0 — Environment Setup

## Objective

Create a simple environment where writing, compiling, testing, and submitting C++ code is easy.

## Recommended Tools

You need:

* C++
* GCC / G++
* A code editor or IDE
* Git
* A competitive programming platform

Possible editors:

* VS Code
* CLion
* Vim/Neovim
* Any editor you are comfortable with

The editor is not important. The ability to quickly write and test code is important.

## Compiler

Verify:

```bash
g++ --version
```

Compile:

```bash
g++ -std=c++17 main.cpp -o main
```

Run:

```bash
./main
```

C++17 is a good baseline for competitive programming.

---

# 3. Phase 1 — C++ Fundamentals

## Objective

Become comfortable writing small programs without constantly looking up basic syntax.

## 3.1 Variables and Data Types

Learn:

```cpp
int
long long
float
double
char
bool
string
```

Pay particular attention to:

```cpp
int
long long
```

because integer overflow is a common source of wrong answers.

Example:

```cpp
long long x = 1000000000000LL;
```

Understand:

* Range
* Signed vs unsigned
* Integer division
* Floating-point precision
* Type conversion

---

## 3.2 Input and Output

Learn:

```cpp
cin
cout
```

Example:

```cpp
int a, b;
cin >> a >> b;
cout << a + b << '\n';
```

Understand:

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

These are commonly used to improve standard input/output performance.

---

## 3.3 Operators

Master:

```text
+
-
*
/
%
==
!=
<
>
<=
>=
&&
||
!
```

The modulo operator `%` is particularly important in CP.

---

## 3.4 Conditions

Learn:

```cpp
if
else if
else
switch
```

Example:

```cpp
if (x % 2 == 0) {
    cout << "Even\n";
} else {
    cout << "Odd\n";
}
```

---

## 3.5 Loops

Master:

```cpp
for
while
do while
```

Standard CP loop:

```cpp
for (int i = 0; i < n; i++) {
    // ...
}
```

Range-based loop:

```cpp
for (int x : v) {
    // ...
}
```

Also understand:

```cpp
break;
continue;
```

---

## 3.6 Functions

Learn:

* Parameters
* Return values
* Function scope
* Pass by value
* Pass by reference
* `const` references

Example:

```cpp
int add(int a, int b) {
    return a + b;
}
```

Reference:

```cpp
void solve(vector<int>& v) {
    // ...
}
```

Const reference:

```cpp
void print(const vector<int>& v) {
    // ...
}
```

---

## 3.7 Arrays

Understand:

```cpp
int a[100];
```

Learn:

* Indexing
* Traversal
* Updating
* Searching
* Basic manipulation

Remember that C++ arrays use zero-based indexing.

---

## 3.8 Strings

Learn:

```cpp
string s;
```

Important operations:

```cpp
s.size()
s[i]
```

Also learn:

* Concatenation
* Comparison
* Substrings
* Character manipulation

---

## 3.9 Basic C++ Concepts

Before leaving this phase, understand:

* Scope
* References
* `const`
* `auto`
* `nullptr`
* Basic structs
* Basic enums
* Header files
* Namespaces

You do not need advanced object-oriented programming at this stage.

---

# 4. Phase 2 — STL Fundamentals

## Objective

Become comfortable with the C++ Standard Template Library.

STL is one of the most important parts of C++ for competitive programming.

---

## 4.1 Vector

Learn:

```cpp
vector<int> v;
```

Important operations:

```cpp
v.push_back(x);
v.pop_back();
v.size();
v.empty();
v.clear();
```

Understand:

* Dynamic size
* Indexing
* Iteration
* Capacity vs size
* Passing vectors to functions

Example:

```cpp
for (int x : v) cout << x << ' ';
```

---

## 4.2 Pair

Learn:

```cpp
pair<int, int> p = {10, 20};
```

Access:

```cpp
p.first
p.second
```

Pairs are heavily used with graphs, sorting, coordinates, and priority queues.

---

## 4.3 Set

Learn:

```cpp
set<int> s;
```

Important operations:

```cpp
s.insert(x);
s.erase(x);
s.find(x);
s.count(x);
```

Understand that `set` maintains sorted unique values.

---

## 4.4 Multiset

Learn when duplicates need to be maintained:

```cpp
multiset<int> ms;
```

Important operations:

```cpp
insert
erase
find
count
lower_bound
upper_bound
```

---

## 4.5 Map

Learn:

```cpp
map<int, int> mp;
```

Very common use:

```cpp
mp[x]++;
```

This can be used for frequency counting.

Understand:

* Key/value structure
* Sorted keys
* Lookup complexity
* Insertion and deletion

---

## 4.6 Unordered Map

Learn:

```cpp
unordered_map<int, int> mp;
```

Understand the difference between:

```text
map
unordered_map
```

In particular:

```text
map            → ordered
unordered_map  → hash table
```

Do not assume `unordered_map` is always faster in every situation.

---

## 4.7 Stack

Learn:

```cpp
stack<int> st;
```

Operations:

```cpp
push
pop
top
empty
size
```

Typical applications:

* Parentheses
* Monotonic stack
* DFS concepts
* Expression processing

---

## 4.8 Queue

Learn:

```cpp
queue<int> q;
```

Operations:

```cpp
push
pop
front
back
empty
```

Important for BFS.

---

## 4.9 Deque

Learn:

```cpp
deque<int> dq;
```

Useful when insertion/removal is needed from both ends.

---

## 4.10 Priority Queue

Max heap:

```cpp
priority_queue<int> pq;
```

Min heap:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Understand:

* Heap
* Maximum extraction
* Minimum extraction
* Priority-based processing

---

# 5. Phase 3 — STL Algorithms

## Objective

Become familiar with the algorithms that appear constantly in CP.

Master:

```cpp
sort()
reverse()
min()
max()
swap()
binary_search()
lower_bound()
upper_bound()
```

Also learn:

```cpp
min_element()
max_element()
accumulate()
count()
find()
```

---

## Sorting

Basic:

```cpp
sort(v.begin(), v.end());
```

Descending:

```cpp
sort(v.rbegin(), v.rend());
```

Custom comparator:

```cpp
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});
```

Eventually understand how to sort:

* Pairs
* Structs
* Objects
* Custom criteria

---

# 6. Phase 4 — Complexity Analysis

## Objective

Learn to estimate whether an algorithm will fit within the problem's constraints.

This is one of the most important CP skills.

---

## Common Complexity Classes

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
O(n³)
O(2ⁿ)
O(n!)
```

Understand their relative growth.

---

## Examples

Linear loop:

```cpp
for (int i = 0; i < n; i++) {
    // ...
}
```

Complexity:

```text
O(n)
```

Nested loops:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // ...
    }
}
```

Complexity:

```text
O(n²)
```

Sorting:

```cpp
sort(v.begin(), v.end());
```

Typically:

```text
O(n log n)
```

---

## Constraint-Based Thinking

Before designing an algorithm, inspect `n`.

For example:

```text
n <= 20
```

may allow exponential techniques.

But:

```text
n <= 200000
```

usually rules out `O(n²)` approaches.

Develop the habit:

```text
Read constraints
    ↓
Estimate allowed complexity
    ↓
Design algorithm
    ↓
Implement
```

---

# 7. Phase 5 — Basic Problem Solving

## Objective

Start solving actual competitive programming problems.

Topics:

* Implementation
* Simulation
* Arrays
* Strings
* Counting
* Basic mathematics
* Sorting
* Frequency counting

---

## 7.1 Implementation

Practice:

* Conditions
* Loops
* Simulations
* State changes
* Multiple test cases

Learn the standard pattern:

```cpp
int t;
cin >> t;

while (t--) {
    solve();
}
```

---

## 7.2 Basic Mathematics

Learn:

* Even/odd
* Divisibility
* Remainders
* GCD
* LCM
* Factors
* Prime checking
* Integer arithmetic

C++ provides:

```cpp
gcd(a, b)
```

with the appropriate standard library support.

---

## 7.3 Prefix Sum

Given:

```text
2 4 1 5 3
```

Prefix sums:

```text
2 6 7 12 15
```

Learn how prefix sums turn repeated range-sum queries into efficient operations.

Basic idea:

```text
prefix[i] = prefix[i - 1] + a[i]
```

---

## 7.4 Frequency Counting

Learn frequency counting using:

```cpp
map
unordered_map
array
vector
```

For small integer ranges, an array can often be simpler and faster than a map.

---

## 7.5 Sorting-Based Problem Solving

Learn to recognize situations where sorting simplifies the problem.

Common pattern:

```text
Input
  ↓
Sort
  ↓
Process sequentially
  ↓
Answer
```

---

# 8. Phase 6 — Searching and Binary Search

## Objective

Master both ordinary searching and binary-search patterns.

---

## 8.1 Linear Search

Complexity:

```text
O(n)
```

---

## 8.2 Binary Search

Understand:

```text
low
mid
high
```

and the invariant maintained by the search.

You should eventually be able to implement binary search manually.

---

## 8.3 STL Binary Search

Learn:

```cpp
binary_search(v.begin(), v.end(), x);
```

and:

```cpp
lower_bound(v.begin(), v.end(), x);
upper_bound(v.begin(), v.end(), x);
```

Understand what iterator each function returns.

---

## 8.4 Binary Search on Answer

This is an important competitive programming technique.

General structure:

```text
Candidate answer X
       ↓
Can X satisfy the requirement?
       ↓
Yes / No
       ↓
Binary search the boundary
```

Typical wording:

* Minimum possible value
* Maximum possible value
* Smallest X satisfying condition
* Largest X satisfying condition

Learn to identify a monotonic feasibility condition.

---

# 9. Phase 7 — Recursion and Backtracking

## Objective

Understand recursive problem decomposition and search over possible choices.

---

## 9.1 Recursion

Understand:

* Base case
* Recursive case
* Call stack
* State
* Progress toward termination

Do not memorize recursive code blindly.

Learn to draw the recursion tree.

---

## 9.2 Subsets

For:

```text
[1, 2, 3]
```

generate:

```text
{}
{1}
{2}
{3}
{1,2}
{1,3}
{2,3}
{1,2,3}
```

---

## 9.3 Permutations

Learn how to generate:

```text
123
132
213
231
312
321
```

---

## 9.4 Backtracking

Typical structure:

```text
Choose
   ↓
Explore
   ↓
Undo
   ↓
Try next choice
```

Applications include:

* Subsets
* Permutations
* Combinations
* Constraint problems
* Grid search
* Basic puzzle problems

---

# 10. Phase 8 — Fundamental Data Structures

## Objective

Understand the underlying structures behind common STL containers.

Learn:

* Arrays
* Dynamic arrays
* Linked lists
* Stacks
* Queues
* Deques
* Hash tables
* Heaps

You should understand how these structures work conceptually even when you use STL implementations in contests.

---

## Linked List

Know:

* Node
* Next pointer
* Traversal
* Insertion
* Deletion

Do not spend excessive time implementing linked lists if your primary goal is CP.

---

## Stack

Understand the LIFO model:

```text
Last In → First Out
```

---

## Queue

Understand the FIFO model:

```text
First In → First Out
```

---

## Heap

Understand:

```text
Min Heap
Max Heap
```

and how `priority_queue` implements heap-based priority processing.

---

# 11. Phase 9 — Trees

## Objective

Learn tree traversal and tree-based problem solving.

---

## 11.1 Binary Trees

Understand:

```text
root
left child
right child
parent
leaf
height
depth
subtree
```

---

## 11.2 DFS Traversals

Learn:

```text
Preorder
Inorder
Postorder
```

---

## 11.3 BFS

Learn level-order traversal.

---

## 11.4 Binary Search Tree

Understand:

```text
left < root < right
```

and the consequences for searching and traversal.

---

## 11.5 Tree DFS

A common CP pattern:

```cpp
void dfs(int node, int parent) {
    for (int next : graph[node]) {
        if (next == parent) continue;
        dfs(next, node);
    }
}
```

This pattern becomes foundational for tree problems.

---

# 12. Phase 10 — Graphs

## Objective

Become comfortable solving graph problems.

Graphs are one of the largest areas of competitive programming.

---

## 12.1 Graph Representation

Learn:

```text
Adjacency Matrix
Adjacency List
Edge List
```

For most CP problems, adjacency lists are extremely common.

Example:

```cpp
vector<vector<int>> graph(n);
```

---

## 12.2 BFS

Learn:

```text
Breadth-First Search
```

Applications:

* Shortest path in unweighted graphs
* Level traversal
* Connected components
* Grid problems
* Multi-source BFS

---

## 12.3 DFS

Learn:

```text
Depth-First Search
```

Applications:

* Connected components
* Cycle detection
* Tree traversal
* Graph exploration
* Topological techniques
* Component analysis

---

## 12.4 Connected Components

Learn how to identify groups of mutually reachable vertices.

---

## 12.5 Cycle Detection

Learn cycle detection in:

* Undirected graphs
* Directed graphs

---

## 12.6 Bipartite Graphs

Learn:

* Two-coloring
* BFS/DFS-based bipartite checking

---

## 12.7 Topological Sort

Learn for directed acyclic graphs.

Methods:

* DFS
* Kahn's algorithm

---

## 12.8 Dijkstra

Learn shortest paths with non-negative edge weights.

Understand:

```text
priority queue
distance array
relaxation
```

---

## 12.9 Disjoint Set Union

Also called:

```text
DSU
Union-Find
```

Learn:

```text
find()
union()
path compression
union by size/rank
```

Applications:

* Connected components
* Dynamic connectivity
* Kruskal's algorithm

---

## 12.10 Minimum Spanning Tree

Learn:

```text
Kruskal
Prim
```

Understand what a spanning tree is and why minimum spanning trees matter.

---

# 13. Phase 11 — Greedy Algorithms

## Objective

Learn when a sequence of locally optimal decisions can produce a globally valid solution.

Common topics:

* Sorting + greedy
* Interval scheduling
* Activity selection
* Priority queue + greedy
* Exchange arguments
* Choosing earliest/latest valid options

The important skill is not memorizing greedy algorithms.

The important skill is recognizing when a greedy strategy can be justified.

---

# 14. Phase 12 — Dynamic Programming

## Objective

Learn how to solve problems involving overlapping subproblems and optimal substructure.

Do not rush into advanced DP.

First become comfortable with:

* Recursion
* State definition
* Transition
* Base cases
* Complexity analysis

---

## 14.1 1D DP

Start with problems such as:

* Fibonacci
* Climbing Stairs
* House Robber
* Simple sequence optimization

Learn:

```text
dp[i]
```

and what exactly it represents.

---

## 14.2 2D DP

Examples:

* Grid paths
* Knapsack
* Grid optimization

Learn:

```text
dp[i][j]
```

---

## 14.3 Knapsack

Master:

```text
0/1 Knapsack
Unbounded Knapsack
```

Understand the difference between:

```text
Take
Don't take
```

and how the state changes.

---

## 14.4 Coin Change

Learn both:

* Minimum number of coins
* Number of ways

These teach different DP transitions.

---

## 14.5 LIS

Learn:

```text
Longest Increasing Subsequence
```

Start with the basic DP solution.

Later learn the optimized:

```text
O(n log n)
```

approach.

---

## 14.6 LCS

Learn:

```text
Longest Common Subsequence
```

This introduces string-based two-dimensional DP.

---

## 14.7 Advanced DP

Later learn:

* Tree DP
* Bitmask DP
* Digit DP
* Interval DP
* DP on DAGs
* DP optimizations

These should come after the fundamentals are strong.

---

# 15. Phase 13 — Number Theory

## Objective

Build the mathematical toolkit commonly required in CP.

---

## Essential Topics

Learn:

* GCD
* LCM
* Prime checking
* Sieve of Eratosthenes
* Prime factorization
* Modular arithmetic
* Fast exponentiation

---

## Modular Arithmetic

Understand:

```text
(a + b) mod M
(a - b) mod M
(a × b) mod M
```

and why modulo is frequently used to prevent huge integer values.

---

## Fast Exponentiation

Learn binary exponentiation:

```text
O(log n)
```

instead of multiplying `n` times.

---

## Advanced Number Theory

Later learn:

* Modular inverse
* Fermat's Little Theorem
* Euler's Totient Function
* Combinatorics
* Chinese Remainder Theorem
* Extended Euclidean Algorithm

Only learn these when problem difficulty requires them.

---

# 16. Phase 14 — Advanced Data Structures

Start this phase after becoming comfortable with medium-level problems.

---

## 16.1 Fenwick Tree

Also called:

```text
Binary Indexed Tree
BIT
```

Learn:

* Point update
* Prefix query
* Range query using prefix differences

Typical complexity:

```text
O(log n)
```

---

## 16.2 Segment Tree

Learn:

```text
Build
Query
Update
```

Applications:

* Range sum
* Range minimum
* Range maximum
* Custom associative operations

Typical complexity:

```text
Build:  O(n)
Query:  O(log n)
Update: O(log n)
```

---

## 16.3 Lazy Propagation

Learn after standard segment trees.

Used for efficient range updates.

---

## 16.4 Sparse Table

Useful for static range queries.

Common application:

```text
Range Minimum Query
```

---

## 16.5 Trie

Learn prefix trees.

Applications:

* Prefix queries
* Dictionary problems
* XOR-related problems
* String search

---

# 17. Phase 15 — Advanced Algorithms

This phase is optional until you reach higher problem difficulty.

---

## Advanced Graph Algorithms

Learn:

* Floyd-Warshall
* Bellman-Ford
* Strongly Connected Components
* Kosaraju
* Tarjan
* Bridges
* Articulation Points
* DAG DP
* Advanced shortest-path techniques

---

## Advanced String Algorithms

Learn:

* KMP
* Z Algorithm
* Rolling Hash
* String Hashing
* Suffix Array
* Suffix-related structures

---

## Advanced Dynamic Programming

Learn:

* Bitmask DP
* Digit DP
* Tree DP
* Interval DP
* DP optimization
* Divide and conquer optimization
* Convex Hull Trick

These topics should be introduced only when your problem-solving level justifies them.

---

# 18. Problem-Solving Methodology

The most important part of competitive programming is not syntax.

It is the process of turning a problem statement into an algorithm.

Use this workflow.

---

## Step 1 — Read the Problem Carefully

Identify:

```text
Input
Output
Constraints
Examples
Special conditions
```

Do not start coding immediately.

---

## Step 2 — Study the Constraints

Ask:

```text
How large can n be?
How many test cases are there?
What complexity can fit?
```

---

## Step 3 — Solve the Examples Manually

Try to understand:

```text
Why does the example produce this output?
```

---

## Step 4 — Find a Brute Force Solution

Even if it is too slow, first understand the straightforward solution.

Then ask:

```text
What makes brute force slow?
```

---

## Step 5 — Find the Bottleneck

Typical bottlenecks:

```text
Nested loops
Repeated searches
Repeated range sums
Repeated sorting
Repeated graph traversal
Large state space
```

---

## Step 6 — Choose the Technique

Look for patterns:

```text
Sorted data
    → Binary Search / Two Pointers

Repeated range sums
    → Prefix Sum

Subarray/window
    → Sliding Window

Frequency
    → Map / Array

Shortest path
    → BFS / Dijkstra

Connected components
    → DFS / BFS / DSU

Overlapping subproblems
    → DP

Range query/update
    → Fenwick / Segment Tree
```

---

## Step 7 — Calculate Complexity

Before coding, estimate:

```text
Time Complexity
Space Complexity
```

---

## Step 8 — Implement

Write clean, simple code.

Avoid unnecessary abstraction during contests.

---

## Step 9 — Test

Test:

* Minimum input
* Maximum input
* Empty/small cases where applicable
* Duplicate values
* Negative values where applicable
* Already sorted data
* Reverse-sorted data
* All values equal
* Overflow cases

---

## Step 10 — Submit

If accepted:

```text
Understand why it works.
```

If rejected:

```text
Analyze the failure.
```

---

# 19. Contest Strategy

Participate in contests regularly.

Useful contest formats include:

* Codeforces
* AtCoder
* ICPC-style contests
* Other online programming contests

The platform matters less than consistent practice.

---

## During a Contest

A useful workflow:

```text
Read all problems
    ↓
Identify easy problems
    ↓
Solve straightforward ones
    ↓
Move to medium problems
    ↓
Return to difficult problems
```

Do not spend the entire contest stuck on one problem unless you have a clear breakthrough path.

---

## After the Contest

The post-contest review is extremely important.

For every unsolved problem:

```text
Read editorial
    ↓
Understand idea
    ↓
Close editorial
    ↓
Implement yourself
    ↓
Submit
```

Do not consider a problem fully learned just because you understood the editorial.

You should be able to implement the solution yourself afterward.

---

# 20. Debugging Strategy

Wrong answers are part of CP.

When you receive a WA:

Do not randomly modify the code.

Instead:

```text
Find smallest failing case
        ↓
Compare expected vs actual
        ↓
Identify incorrect assumption
        ↓
Fix algorithm
        ↓
Retest
```

---

## Common Sources of Wrong Answers

### Integer Overflow

Use:

```cpp
long long
```

when constraints require it.

---

### Off-by-One Errors

Be careful with:

```text
i < n
```

vs:

```text
i <= n
```

---

### Incorrect Binary Search

Check:

```text
Loop invariant
mid calculation
boundary updates
termination
```

---

### Incorrect Initialization

Especially common in:

```text
DP
BFS
Dijkstra
prefix sums
```

---

### Forgetting Multiple Test Cases

Always check whether:

```text
t
```

exists.

---

### Incorrect Graph Traversal

Watch for:

```text
visited array
parent
directed vs undirected edges
```

---

# 21. What NOT to Learn Initially

If your primary goal is competitive programming, do not spend months learning general C++ software engineering before solving problems.

Initially deprioritize:

```text
Advanced OOP
Inheritance hierarchies
Design patterns
GUI programming
Multithreading
Complex CMake configuration
Template metaprogramming
Custom memory allocators
Large software architecture
Enterprise application design
Advanced exception architecture
```

These can be learned later for software development.

For CP, prioritize:

```text
Algorithms
Data Structures
STL
Complexity
Mathematics
Problem Solving
```

---

# 22. Recommended Weekly Schedule

Assuming approximately 2 hours per day:

## Monday–Friday

```text
30 min → Learn/review concept
60 min → Solve problems
30 min → Review mistakes
```

---

## Saturday

Participate in a contest or complete a virtual contest.

Example:

```text
Contest
    ↓
Submit solutions
    ↓
Record unsolved problems
```

---

## Sunday

Use Sunday for review:

```text
Wrong submissions
Editorials
Re-solving
Notes
Weak topics
```

---

# 23. Progression System

Do not measure progress only by the number of problems solved.

Track:

```text
Problems attempted
Problems solved independently
Problems solved after hints
Problems solved after editorial
Contest performance
Topics mastered
Recurring mistakes
```

---

## Difficulty Progression

A useful progression is:

```text
800
 ↓
900
 ↓
1000
 ↓
1100
 ↓
1200
 ↓
1300
 ↓
1400
 ↓
1500
 ↓
1600+
```

Difficulty numbers vary by platform and over time, so treat them as approximate milestones rather than absolute measures.

The important progression is:

```text
Can implement
    ↓
Can recognize pattern
    ↓
Can derive solution
    ↓
Can solve unfamiliar variation
    ↓
Can solve under contest time pressure
```

---

# 24. Project Structure

A practical GitHub repository can look like this:

```text
cpp-competitive-programming/
│
├── README.md
│
├── 01-basics/
│   ├── variables.cpp
│   ├── conditions.cpp
│   ├── loops.cpp
│   ├── functions.cpp
│   ├── arrays.cpp
│   └── strings.cpp
│
├── 02-stl/
│   ├── vector.cpp
│   ├── pair.cpp
│   ├── set.cpp
│   ├── map.cpp
│   ├── stack.cpp
│   ├── queue.cpp
│   └── priority_queue.cpp
│
├── 03-algorithms/
│   ├── sorting.cpp
│   ├── binary_search.cpp
│   ├── lower_bound.cpp
│   └── upper_bound.cpp
│
├── 04-complexity/
│   └── examples.cpp
│
├── 05-basic-problems/
│   ├── arrays/
│   ├── strings/
│   ├── math/
│   └── implementation/
│
├── 06-searching/
│   ├── binary-search/
│   └── answer-search/
│
├── 07-recursion/
│   ├── recursion/
│   └── backtracking/
│
├── 08-data-structures/
│   ├── linked-list/
│   ├── stack/
│   ├── queue/
│   └── heap/
│
├── 09-trees/
│
├── 10-graphs/
│   ├── bfs/
│   ├── dfs/
│   ├── dijkstra/
│   ├── dsu/
│   └── mst/
│
├── 11-greedy/
│
├── 12-dp/
│   ├── 1d/
│   ├── 2d/
│   ├── knapsack/
│   ├── lis/
│   └── lcs/
│
├── 13-number-theory/
│
├── 14-advanced-data-structures/
│   ├── fenwick/
│   ├── segment-tree/
│   ├── sparse-table/
│   └── trie/
│
└── 15-advanced-algorithms/
    ├── advanced-graphs/
    ├── strings/
    └── advanced-dp/
```

The exact structure is not important. Consistency is.

---

# 25. Master Checklist

## C++ Fundamentals

* [ ] Variables
* [ ] Data types
* [ ] Input/output
* [ ] Operators
* [ ] Conditions
* [ ] Loops
* [ ] Functions
* [ ] References
* [ ] Arrays
* [ ] Strings
* [ ] Basic structs
* [ ] `const`
* [ ] `auto`

---

## STL

* [ ] Vector
* [ ] Pair
* [ ] Set
* [ ] Multiset
* [ ] Map
* [ ] Unordered map
* [ ] Stack
* [ ] Queue
* [ ] Deque
* [ ] Priority queue
* [ ] Iterators

---

## STL Algorithms

* [ ] Sort
* [ ] Reverse
* [ ] Min/max
* [ ] Min/max element
* [ ] Binary search
* [ ] Lower bound
* [ ] Upper bound
* [ ] Find
* [ ] Count
* [ ] Accumulate

---

## Complexity

* [ ] O(1)
* [ ] O(log n)
* [ ] O(n)
* [ ] O(n log n)
* [ ] O(n²)
* [ ] O(2ⁿ)
* [ ] O(n!)
* [ ] Space complexity
* [ ] Constraint analysis

---

## Basic Techniques

* [ ] Prefix sum
* [ ] Frequency counting
* [ ] Sorting
* [ ] Two pointers
* [ ] Sliding window
* [ ] Binary search
* [ ] Binary search on answer

---

## Recursion

* [ ] Base case
* [ ] Recursive state
* [ ] Recursion tree
* [ ] Subsets
* [ ] Permutations
* [ ] Combinations
* [ ] Backtracking

---

## Trees

* [ ] Binary tree
* [ ] DFS
* [ ] BFS
* [ ] Preorder
* [ ] Inorder
* [ ] Postorder
* [ ] BST
* [ ] Tree DFS

---

## Graphs

* [ ] Adjacency list
* [ ] BFS
* [ ] DFS
* [ ] Connected components
* [ ] Cycle detection
* [ ] Bipartite graph
* [ ] Topological sort
* [ ] Dijkstra
* [ ] DSU
* [ ] Kruskal
* [ ] Prim

---

## Greedy

* [ ] Sorting + greedy
* [ ] Interval scheduling
* [ ] Priority queue + greedy
* [ ] Greedy proof
* [ ] Exchange argument

---

## Dynamic Programming

* [ ] DP state
* [ ] Transition
* [ ] Base cases
* [ ] 1D DP
* [ ] 2D DP
* [ ] Knapsack
* [ ] Coin change
* [ ] LIS
* [ ] LCS
* [ ] Grid DP
* [ ] Tree DP
* [ ] Bitmask DP
* [ ] Digit DP
* [ ] Interval DP

---

## Number Theory

* [ ] GCD
* [ ] LCM
* [ ] Prime checking
* [ ] Sieve
* [ ] Prime factorization
* [ ] Modular arithmetic
* [ ] Fast exponentiation
* [ ] Modular inverse
* [ ] Fermat's Little Theorem
* [ ] Euler Totient
* [ ] Extended Euclidean Algorithm

---

## Advanced Data Structures

* [ ] Fenwick Tree
* [ ] Segment Tree
* [ ] Lazy Propagation
* [ ] Sparse Table
* [ ] Trie

---

## Advanced Algorithms

* [ ] Floyd-Warshall
* [ ] Bellman-Ford
* [ ] SCC
* [ ] Bridges
* [ ] Articulation Points
* [ ] KMP
* [ ] Z Algorithm
* [ ] Rolling Hash
* [ ] Suffix Array
* [ ] Advanced DP

---

# Final Learning Philosophy

The purpose of this roadmap is not to memorize hundreds of algorithms.

The actual objective is to develop the ability to look at a new problem and ask:

```text
What is the structure of this problem?
        ↓
What are the constraints?
        ↓
What is the simplest solution?
        ↓
Why is it too slow?
        ↓
What pattern removes the bottleneck?
        ↓
Which data structure or algorithm fits?
        ↓
Can I prove that it works?
        ↓
Can I implement it correctly?
```

A strong competitive programmer eventually develops pattern recognition.

For example:

```text
Range sums
    → Prefix Sum

Sorted search
    → Binary Search

Contiguous subarray
    → Sliding Window / Two Pointers

Frequency
    → Map / Hash Map / Array

Shortest unweighted path
    → BFS

Shortest weighted path
    → Dijkstra

Connectivity
    → DFS / BFS / DSU

Overlapping subproblems
    → Dynamic Programming

Range queries
    → Fenwick Tree / Segment Tree
```

Do not rush through the roadmap.

It is better to deeply understand **10 important techniques** and solve many variations than to memorize **100 algorithms** without knowing when to use them.

The ultimate progression is:

```text
Learn C++
    ↓
Learn STL
    ↓
Learn Algorithms
    ↓
Solve Problems
    ↓
Make Mistakes
    ↓
Analyze Mistakes
    ↓
Recognize Patterns
    ↓
Solve Faster
    ↓
Compete
```

## Primary Goal

Become a programmer who can take an unfamiliar problem, derive an efficient algorithm, prove the idea to yourself, and implement it reliably in C++ under time constraints.

That is the core skill this roadmap is designed to build.

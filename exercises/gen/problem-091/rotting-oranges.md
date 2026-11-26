# Rotting Oranges

- **Difficulty:** Medium
- **Topics:** Graph, BFS

## Problem Statement

Every minute, fresh oranges (1) adjacent to rotten (2) become rotten. Find the minimum minutes until no fresh orange remains, or -1 if impossible.

## Input Format

First line: m and n. Next m lines: n space-separated values (0 empty, 1 fresh, 2 rotten).

## Output Format

Print the minimum minutes or -1.

## Examples

**Example 1**

Input:
```
3 3
2 1 1
1 1 0
0 1 1
```

Output:
```
4
```

**Example 2**

Input:
```
3 3
2 1 1
0 1 1
1 0 1
```

Output:
```
-1
```

**Example 3**

Input:
```
1 1
0
```

Output:
```
0
```


## Constraints

- 1 <= m, n <= 10

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

# Combination Sum

- **Difficulty:** Medium
- **Topics:** Backtracking

## Problem Statement

Given distinct candidates and a target, return all unique combinations where chosen numbers sum to target; candidates may be reused. Print each combination on its own line (sorted), any order.

## Input Format

First line: n and target. Second line: n distinct candidates.

## Output Format

Print each combination space-separated on its own line.

## Examples

**Example 1**

Input:
```
4 7
2 3 6 7
```

Output:
```
7
2 2 3
```

**Example 2**

Input:
```
3 7
2 3 5
```

Output:
```
2 2 3
2 5
```

**Example 3**

Input:
```
3 8
2 3 5
```

Output:
```
2 2 2 2
2 3 3
3 5
```


## Constraints

- 1 <= n <= 30, 1 <= candidates[i] <= 200

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

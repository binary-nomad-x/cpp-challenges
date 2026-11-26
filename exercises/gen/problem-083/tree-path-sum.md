# Tree Path Sum

- **Difficulty:** Easy
- **Topics:** Tree, DFS

## Problem Statement

Given a binary tree and targetSum, determine whether the tree has a root-to-leaf path whose values sum to targetSum.

## Input Format

First line: n and targetSum. Second line: n level-order values (-1 = null).

## Output Format

Print true or false.

## Examples

**Example 1**

Input:
```
5 22
5 4 8 11 -1 13 4 7 2 -1 -1 -1 1
```

Output:
```
true
```

**Example 2**

Input:
```
3 5
1 2 3
```

Output:
```
false
```

**Example 3**

Input:
```
0 0

```

Output:
```
false
```


## Constraints

- 0 <= n <= 5000, values may be negative

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

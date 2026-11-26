# Flood Fill

- **Difficulty:** Easy
- **Topics:** Graph, DFS

## Problem Statement

Given an image (m x n grid of colors), a starting pixel, and a new color, replace the connected same-color region (4-directional) with the new color.

## Input Format

First line: m n sr sc newColor. Next m lines: n colors each.

## Output Format

Print the final image, colors space-separated.

## Examples

**Example 1**

Input:
```
3 3 1 1 2
1 1 1
1 1 0
1 0 1
```

Output:
```
2 2 2
2 2 0
2 0 1
```

**Example 2**

Input:
```
2 2 0 0 0
0 0
0 0
0 0
```

Output:
```
0 0
```


## Constraints

- 1 <= m, n <= 50

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

# Daily Temperatures

- **Difficulty:** Medium
- **Topics:** Stack

## Problem Statement

Given daily temperatures, return an array where answer[i] is the number of days to wait after the i-th day to get a warmer temperature (0 if none).

## Input Format

First line: n. Second line: n temperatures.

## Output Format

Print the answer array space-separated.

## Examples

**Example 1**

Input:
```
8
73 74 75 71 69 72 76 73
```

Output:
```
1 1 4 2 1 1 0 0
```

**Example 2**

Input:
```
4
30 40 50 60
```

Output:
```
1 1 1 0
```


## Constraints

- 1 <= n <= 10^5, 30 <= temperatures[i] <= 100

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

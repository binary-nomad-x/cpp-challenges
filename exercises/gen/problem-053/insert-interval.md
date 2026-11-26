# Insert Interval

- **Difficulty:** Medium
- **Topics:** Sorting

## Problem Statement

Given a sorted non-overlapping list of intervals and a new interval, insert the new interval and merge if necessary. Print the resulting list, one per line.

## Input Format

First line: n. Next n lines: 'start end'. Last line: the new interval 'start end'.

## Output Format

Print merged intervals one per line.

## Examples

**Example 1**

Input:
```
2
1 3
6 9
2 5
```

Output:
```
1 5
6 9
```

**Example 2**

Input:
```
1
1 5
0 0
```

Output:
```
0 0
1 5
```


## Constraints

- 0 <= n <= 10^4

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

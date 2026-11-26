# Min Stack Design

- **Difficulty:** Medium
- **Topics:** Stack, Design

## Problem Statement

Design a stack that supports push, pop, top, and retrieving the minimum element in O(1). Process q queries: push x, pop, top, getMin.

## Input Format

First line: q. Next q lines: push x | pop | top | getMin.

## Output Format

Print output of each top/getMin query on its own line.

## Examples

**Example 1**

Input:
```
6
push -2
push 0
push -3
getMin
pop
top
getMin
```

Output:
```
-3
0
-2
```


## Constraints

- 1 <= q <= 3*10^4, -2^31 <= x <= 2^31-1; pop/top/getMin always valid

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

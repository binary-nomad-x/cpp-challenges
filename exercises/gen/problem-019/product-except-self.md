# Product Except Self

- **Difficulty:** Medium
- **Topics:** Array, Prefix/Suffix

## Problem Statement

Given an array of n integers, return an array answer where answer[i] is the product of all elements except nums[i]. Do it without division and in O(n).

## Input Format

First line: n. Second line: n space-separated integers (no zeros).

## Output Format

Print the answer array space-separated.

## Examples

**Example 1**

Input:
```
4
1 2 3 4
```

Output:
```
24 12 8 6
```

**Example 2**

Input:
```
5
```

Output:
```
-1 1 0 -3 3
```


## Constraints

- 2 <= n <= 10^5 (the second example contains a zero; assume no zeros or handle them)

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

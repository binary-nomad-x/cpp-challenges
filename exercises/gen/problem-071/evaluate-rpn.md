# Evaluate RPN

- **Difficulty:** Medium
- **Topics:** Stack, Math

## Problem Statement

Evaluate an arithmetic expression in Reverse Polish Notation (integer division truncates toward zero). Print the result.

## Input Format

First line: n tokens. Second line: n tokens space-separated (integers or + - * /).

## Output Format

Print the result.

## Examples

**Example 1**

Input:
```
5
2 1 + 3 *
```

Output:
```
9
```

**Example 2**

Input:
```
5
4 13 5 / +
```

Output:
```
6
```

**Example 3**

Input:
```
13
10 6 9 3 + -11 * / * 17 + 5 +
```

Output:
```
22
```


## Constraints

- 1 <= n <= 10^4, answer fits 32-bit

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

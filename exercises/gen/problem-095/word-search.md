# Word Search

- **Difficulty:** Medium
- **Topics:** Graph, Backtracking

## Problem Statement

Given an m x n board of letters and a word, determine whether the word exists in the grid moving 4-directionally without reusing a cell.

## Input Format

First line: m n. Next m lines: n characters each. Last line: the word.

## Output Format

Print true or false.

## Examples

**Example 1**

Input:
```
3 4
ABCE
SFCS
ADEE
ABCCED
```

Output:
```
true
```

**Example 2**

Input:
```
3 4
ABCE
SFCS
ADEE
SEE
```

Output:
```
true
```

**Example 3**

Input:
```
3 4
ABCE
SFCS
ADEE
ABCB
```

Output:
```
false
```


## Constraints

- 1 <= m, n <= 6, 1 <= word.length <= 15

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

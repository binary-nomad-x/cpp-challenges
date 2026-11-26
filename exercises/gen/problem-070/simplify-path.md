# Simplify Path

- **Difficulty:** Medium
- **Topics:** Stack, Strings

## Problem Statement

Given an absolute Unix path, return its simplified canonical path (handle '.', '..', multiple slashes, trailing slash).

## Input Format

First line: path string.

## Output Format

Print the canonical path (starting with /).

## Examples

**Example 1**

Input:
```
/home/
```

Output:
```
/home
```

**Example 2**

Input:
```
/../
```

Output:
```
/
```

**Example 3**

Input:
```
/home//foo/
```

Output:
```
/home/foo
```

**Example 4**

Input:
```
/a/./b/../../c/
```

Output:
```
/c
```


## Constraints

- 1 <= path.length <= 3000

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

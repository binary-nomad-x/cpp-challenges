# Decode String

- **Difficulty:** Medium
- **Topics:** Stack, Recursion

## Problem Statement

Given an encoded string like 3[a2[c]], decode it (digits repeat the following bracketed substring). Print the decoded string.

## Input Format

First line: encoded string (digits 1-9, lowercase letters, brackets).

## Output Format

Print the decoded string.

## Examples

**Example 1**

Input:
```
3[a]2[bc]
```

Output:
```
aaabcbc
```

**Example 2**

Input:
```
3[a2[c]]
```

Output:
```
accaccacc
```

**Example 3**

Input:
```
2[abc]3[cd]ef
```

Output:
```
abcabccdcdcdef
```


## Constraints

- 1 <= s.length <= 30

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

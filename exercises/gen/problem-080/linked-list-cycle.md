# Linked List Cycle

- **Difficulty:** Easy
- **Topics:** Linked List, Floyd

## Problem Statement

Given a linked list described by values and a position pos where the tail connects (-1 means no cycle), determine whether a cycle exists.

## Input Format

First line: n and pos (-1 if none). Second line: n list values.

## Output Format

Print true or false.

## Examples

**Example 1**

Input:
```
4 1
3 2 0 -4
```

Output:
```
true
```

**Example 2**

Input:
```
2 -1
1 2
```

Output:
```
false
```

**Example 3**

Input:
```
0 -1

```

Output:
```
false
```


## Constraints

- 0 <= n <= 10^4, pos is -1 or a valid index

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

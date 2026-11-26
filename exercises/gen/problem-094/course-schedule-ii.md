# Course Schedule II

- **Difficulty:** Medium
- **Topics:** Graph, Topological Sort

## Problem Statement

Given numCourses and prerequisites, return any valid order to take all courses; print -1 if impossible.

## Input Format

First line: numCourses and m. Next m lines: 'a b' (b before a).

## Output Format

Print a valid ordering space-separated, or -1.

## Examples

**Example 1**

Input:
```
4 4
1 0
2 0
3 1
3 2
```

Output:
```
0 1 2 3
```

**Example 2**

Input:
```
2 2
1 0
0 1
```

Output:
```
-1
```


## Constraints

- 1 <= numCourses <= 2000

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

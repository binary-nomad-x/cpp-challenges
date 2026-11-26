# Course Schedule

- **Difficulty:** Medium
- **Topics:** Graph, Topological Sort

## Problem Statement

Given numCourses and prerequisites pairs, determine whether you can finish all courses (no cycle).

## Input Format

First line: numCourses and m. Next m lines: 'a b' meaning course b must be taken before a.

## Output Format

Print true or false.

## Examples

**Example 1**

Input:
```
2 1
1 0
```

Output:
```
true
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
false
```

**Example 3**

Input:
```
5 4
1 0
2 0
3 1
3 2
```

Output:
```
true
```


## Constraints

- 1 <= numCourses <= 2000, 0 <= m <= 5000

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

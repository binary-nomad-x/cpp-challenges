# Implement Trie

- **Difficulty:** Medium
- **Topics:** Trie, Design

## Problem Statement

Implement a trie with insert, search (word exists), startsWith (some word with prefix). Process q queries.

## Input Format

First line: q. Next q lines: insert word | search word | startsWith word.

## Output Format

Print true/false for each search and startsWith query on its own line.

## Examples

**Example 1**

Input:
```
6
insert apple
search apple
search app
startsWith app
insert app
search app
```

Output:
```
true
false
true
true
```


## Constraints

- 1 <= q <= 3*10^4, 1 <= word.length <= 2000

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

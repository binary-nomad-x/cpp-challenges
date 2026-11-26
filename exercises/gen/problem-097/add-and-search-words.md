# Add and Search Words

- **Difficulty:** Medium
- **Topics:** Trie, Design

## Problem Statement

Design a dictionary with addWord(word) and search(word) where '.' matches any single letter. Process q queries.

## Input Format

First line: q. Next q lines: addWord word | search word.

## Output Format

Print true/false for each search on its own line.

## Examples

**Example 1**

Input:
```
7
addWord bad
addWord dad
addWord mad
search pad
search bad
search .ad
search b..
```

Output:
```
false
true
true
true
```


## Constraints

- 1 <= q <= 50000, 1 <= word.length <= 25

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

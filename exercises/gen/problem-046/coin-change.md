# Coin Change

- **Difficulty:** Medium
- **Topics:** DP

## Problem Statement

Given coins of different denominations and an amount, compute the fewest number of coins needed to make up that amount. Return -1 if the amount cannot be made.

## Input Format

First line: amount. Second line: number of coins m, then m coin values (or just list them). Input: amount on line 1, coins on line 2.

## Output Format

Print the fewest coins or -1.

## Examples

**Example 1**

Input:
```
11
1 2 5
```

Output:
```
3
```

**Example 2**

Input:
```
3
2
```

Output:
```
-1
```

**Example 3**

Input:
```
0
1
```

Output:
```
0
```


## Constraints

- 1 <= coins.length <= 12, 0 <= amount <= 10^4

---

**Your Task:** Solve this problem in **C++ (C++17)**. Read input from standard input and write the answer to standard output. Do not include explanations — only the required output.

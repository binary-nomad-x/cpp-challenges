Chalo ek **medium-ish but approachable** LeetCode-style challenge:

## 🧩 Challenge: Longest Consecutive Sequence

Tumhein integers ki unsorted array di jayegi. Find karo **longest consecutive elements sequence ki length**.

Sequence mein numbers consecutive hone chahiye:

```text
1, 2, 3, 4
```

order original array mein hona zaroori nahi.

### Example 1

```text
Input:
[100, 4, 200, 1, 3, 2]

Output:
4
```

Because longest sequence hai:

```text
1, 2, 3, 4
```

### Example 2

```text
Input:
[0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

Output:
9
```

Sequence:

```text
0, 1, 2, 3, 4, 5, 6, 7, 8
```

### Example 3

```text
Input:
[1, 1, 2, 2, 3]

Output:
3
```

### Constraints

```text
1 <= nums.size() <= 100,000
-1,000,000,000 <= nums[i] <= 1,000,000,000
```

### Your target

Try to achieve:

```text
Time:  O(n)
Space: O(n)
```

**Bonus:** `sort()` use karke `O(n log n)` solution mat dena. 😈

Expected function:

```cpp
static int longestConsecutive(const vector<int>& nums);
```

**Don't Google it.** Isme ek neat little observation hai jo solution ko kaafi elegant bana deta hai.

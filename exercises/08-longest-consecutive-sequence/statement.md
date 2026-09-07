# 🧩 Longest Consecutive Sequence - Complete Explanation

## 📋 Problem Statement

Given an **unsorted array** of integers, find the **length of the longest consecutive elements sequence**.

A consecutive sequence means numbers that follow each other without gaps:

```text
1, 2, 3, 4  ✅ Consecutive
1, 3, 4, 5  ❌ Not consecutive (missing 2)
```

**Important:** The numbers don't need to appear in order in the original array.

---

## 🎯 Examples Explained

### Example 1: `[100, 4, 200, 1, 3, 2]`

```
Original Array: [100, 4, 200, 1, 3, 2]

Let's find all consecutive sequences:
┌─────────────────────────────────────────────────┐
│ Sequence 1: 1, 2, 3, 4   → Length: 4 ✅        │
│ Sequence 2: 100          → Length: 1            │
│ Sequence 3: 200          → Length: 1            │
└─────────────────────────────────────────────────┘

Output: 4
```

**Visual Representation:**

```
Numbers in array:    1, 2, 3, 4, 100, 200
                       ╰───────╯     ╰─╯   ╰─╯
                       Length: 4   Len:1  Len:1
```

### Example 2: `[0, 3, 7, 2, 5, 8, 4, 6, 0, 1]`

```
Original Array: [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

Let's find all consecutive sequences:
┌─────────────────────────────────────────────────────────┐
│ Sequence: 0, 1, 2, 3, 4, 5, 6, 7, 8   → Length: 9 ✅  │
└─────────────────────────────────────────────────────────┘

Wait! But there are TWO zeros in the array (0 and 0).
Does that matter? No! Because we only care about UNIQUE numbers.
Duplicates don't affect the sequence length.

Output: 9
```

**Visual Representation:**

```
Array elements:  0, 3, 7, 2, 5, 8, 4, 6, 0, 1
Sorted unique:   0, 1, 2, 3, 4, 5, 6, 7, 8
                  ╰──────────────────────────╯
                              Length: 9
```

### Example 3: `[1, 1, 2, 2, 3]`

```
Original Array: [1, 1, 2, 2, 3]

Let's find all consecutive sequences:
┌─────────────────────────────────────────────────┐
│ Sequence: 1, 2, 3          → Length: 3 ✅        │
└─────────────────────────────────────────────────┘

Important: Duplicates (1 and 2 appear twice) don't count twice!
We only count each unique number once.

Output: 3
```

**Visual Representation:**

```
Array:    1, 1, 2, 2, 3
Unique:   {1, 2, 3}
Sequence: 1 → 2 → 3
Length:   3

Even though 1 and 2 appear twice, they're counted once.
```

---

## 💡 The Key Insight

### The Problem with Brute Force

```cpp
// ❌ BAD: Brute Force - O(n²)
for each num in array:
    count = 1
    while (num+1 exists in array):
        count++
        num++
    max = max(max, count)
```

This is slow because for each element, we keep searching the entire array.

### The Smart Approach 🧠

**Key Observation:** For any sequence, we only need to start counting from the **SMALLEST** number.

```
Example: [1, 2, 3, 4, 100]

Numbers: 1, 2, 3, 4, 100
         ╰──────────╯     ╰─╯
         Start: 1        Start: 100
         
We only start counting from 1 and 100.
Why not start from 2, 3, or 4?
Because they're already part of the sequence starting from 1!
```

**How to identify the start of a sequence?**

```text
A number is the START of a sequence if (number - 1) does NOT exist.
```

```
Example 1: [1, 2, 3, 4]
- 1: Is 0 in set? No → START ✅
- 2: Is 1 in set? Yes → NOT START ❌
- 3: Is 2 in set? Yes → NOT START ❌
- 4: Is 3 in set? Yes → NOT START ❌

Example 2: [100, 4, 200, 1, 3, 2]
- 100: Is 99 in set? No → START ✅
- 4: Is 3 in set? Yes → NOT START ❌
- 200: Is 199 in set? No → START ✅
- 1: Is 0 in set? No → START ✅
- 3: Is 2 in set? Yes → NOT START ❌
- 2: Is 1 in set? Yes → NOT START ❌
```

---

## 🔍 Step-by-Step Solution

### Step 1: Create a Hash Set

```cpp
unordered_set<int> numSet;
for (int num : nums) {
    numSet.insert(num);
}
```

**Why hash set?**

- O (1) average time to check if a number exists
- Automatically removes duplicates
- Perfect for "does this number exist" queries

### Step 2: Find Sequence Starts

```cpp
for (int num : numSet) {
    // Check if this is the start of a sequence
    if (numSet.find(num - 1) == numSet.end()) {
        // START FOUND! Now count the sequence
        int currentNum = num;
        int currentStreak = 1;
        
        while (numSet.find(currentNum + 1) != numSet.end()) {
            currentNum++;
            currentStreak++;
        }
        
        longestStreak = max(longestStreak, currentStreak);
    }
}
```

### Step 3: Visual Walkthrough

Let's trace `[100, 4, 200, 1, 3, 2]`:

```
Set = {1, 2, 3, 4, 100, 200}

Iteration 1: num = 100
  Is 99 in set? No ✅ START
  Count: 100 → 101? No. Streak = 1
  longestStreak = max(0, 1) = 1

Iteration 2: num = 4
  Is 3 in set? Yes ❌ NOT START (skip)

Iteration 3: num = 200
  Is 199 in set? No ✅ START
  Count: 200 → 201? No. Streak = 1
  longestStreak = max(1, 1) = 1

Iteration 4: num = 1
  Is 0 in set? No ✅ START
  Count: 1 → 2? Yes! 2 → 3? Yes! 3 → 4? Yes! 4 → 5? No.
  Streak = 4 (1, 2, 3, 4)
  longestStreak = max(1, 4) = 4 ✅

Iteration 5: num = 3
  Is 2 in set? Yes ❌ NOT START (skip)

Iteration 6: num = 2
  Is 1 in set? Yes ❌ NOT START (skip)

Final: longestStreak = 4
```

---

## 🚀 Complete C++ Solution

```cpp
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Find the length of the longest consecutive elements sequence.
     * 
     * Time Complexity: O(n) - Each element is visited at most twice
     * Space Complexity: O(n) - Hash set storage
     * 
     * @param nums Vector of integers (unsorted, may contain duplicates)
     * @return Length of the longest consecutive sequence
     */
    static int longestConsecutive(const vector<int>& nums) {
        // Edge case: empty array
        if (nums.empty()) {
            return 0;
        }

        // Step 1: Insert all numbers into a hash set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longestStreak = 0;

        // Step 2: Iterate through each unique number
        for (int num : numSet) {
            // Only start counting if this is the START of a sequence
            // If (num - 1) exists, this is NOT the start
            if (numSet.find(num - 1) == numSet.end()) {
                // Found the start of a sequence!
                int currentNum = num;
                int currentStreak = 1;

                // Count how many consecutive numbers exist
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update the longest streak found
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
```

---

## 📊 Complexity Analysis

### Time Complexity: O (n)

```
Explanation:
┌─────────────────────────────────────────────────────────────┐
│ Step 1: Insert all elements into set        → O(n)         │
│ Step 2: Iterate through set                 → O(n)         │
│ Step 3: While loop counting sequences       → O(n) total   │
├─────────────────────────────────────────────────────────────┤
│ Total: O(n) + O(n) + O(n) = O(3n) = O(n)                   │
└─────────────────────────────────────────────────────────────┘

Why is the while loop O(n) total?
- Each number is visited at most TWICE:
  1. Once when checking if it's the start (num-1 check)
  2. Once when counting the sequence (as currentNum)

Example: [1, 2, 3, 4, 5]
- 1: Visited as start, then 2, 3, 4, 5 in while loop
- 2, 3, 4, 5: Visited once when checking if (num-1) exists
Total visits: 5 (start) + 4 (while) = 9 ≈ 2n
```

### Space Complexity: O (n)

```
Explanation:
- We store all unique numbers in hash set
- In worst case (all numbers unique): set size = n
- Hash set overhead is O(n)
```

---

## 🎯 Why This Solution is Elegant

### 1. **Avoids Sorting**

```cpp
// ❌ Bad: O(n log n)
sort(nums.begin(), nums.end());  // We don't need this!

// ✅ Good: O(n)
unordered_set<int> numSet(nums.begin(), nums.end());
```

### 2. **Smart Start Detection**

```cpp
// Instead of checking every number in sequence,
// we only check where sequences start
if (numSet.find(num - 1) == numSet.end()) {
    // START FOUND! 🎉
}
```

### 3. **Duplicate Handling**

```cpp
// Set automatically removes duplicates
// [1, 1, 2, 2, 3] → {1, 2, 3}
// We count each number once
```

### 4. **Zero Extra Work**

```cpp
// Each number is processed exactly once as a start,
// and maybe once more during counting
// No number is ever processed twice unnecessarily
```

---

## 🧪 Test Cases

```cpp
// Test Case 1: Basic case
Input:  [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: 1, 2, 3, 4

// Test Case 2: Large sequence
Input:  [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation: 0, 1, 2, 3, 4, 5, 6, 7, 8

// Test Case 3: Duplicates
Input:  [1, 1, 2, 2, 3]
Output: 3
Explanation: 1, 2, 3

// Test Case 4: Empty array
Input:  []
Output: 0

// Test Case 5: Single element
Input:  [5]
Output: 1

// Test Case 6: Negative numbers
Input:  [-2, -1, 0, 1, 2]
Output: 5

// Test Case 7: Gap in middle
Input:  [1, 2, 3, 5, 6, 7]
Output: 3
Explanation: Two sequences: [1,2,3] and [5,6,7]

// Test Case 8: Large numbers
Input:  [1000000000, 999999999, 999999998]
Output: 3
Explanation: 999999998, 999999999, 1000000000
```

---

## 🏆 Summary

### The Magic Formula

```
1. Put all numbers in a hash set (O(1) lookups)
2. For each number, check if it's the START of a sequence
3. START = (num - 1) DOES NOT exist in set
4. If START, count the sequence: num, num+1, num+2, ...
5. Keep track of the maximum length
```

### Key Takeaways

| Concept             | Explanation                            |
|---------------------|----------------------------------------|
| **Hash Set**        | O(1) lookups make this possible        |
| **Start Detection** | Only process sequence beginnings       |
| **No Sorting**      | O(n) instead of O(n log n)             |
| **Duplicates**      | Automatically handled by set           |
| **Memory**          | O(n) space is acceptable for O(n) time |

### Remember This Pattern!

This pattern appears in many problems:

- Find longest sequence
- Find missing number
- Find duplicates
- Find if all elements are consecutive
- Find range of elements

**The key insight:** Use a hash set and only start from the smallest element!

---

## 💪 Practice Challenge

Now try to solve these variations:

1. **Find all consecutive sequences** (return all sequences, not just length)
2. **Find the missing number** in a consecutive sequence
3. **Find the start and end** of the longest sequence
4. **Handle streaming data** (numbers coming one by one)
5. **Find longest sequence in 2D array** (matrix of numbers)


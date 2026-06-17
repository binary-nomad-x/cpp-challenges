### Coding Challenge: The Smallest Missing Positive Integer

---

#### **Problem Statement**

Given an unsorted integer array, find the **smallest missing positive integer**.

In other words, you need to find the lowest integer $x$ such that $x > 0$ and $x$ is not present in the array.

#### **Constraints**

1. **Time Complexity:** Ideally, your solution should run in **$O(n)$** time.
2. **Space Complexity:** Try to achieve this with **$O(1)$** auxiliary space (modifying the input array in-place).
3. **Note:** Ignore zero ($0$) and negative integers.

---

#### **Examples**

| Input           | Output | Explanation                                               |
|:----------------|:-------|:----------------------------------------------------------|
| `[3, 4, -1, 1]` | **2**  | 1 is present, but the next positive integer 2 is missing. |
| `[1, 2, 0]`     | **3**  | 1 and 2 are present, so the smallest missing is 3.        |
| `[7, 8, 9, 11]` | **1**  | The smallest positive integer 1 is not in the array.      |
| `[1, 1, 1]`     | **2**  | 1 is present, so the smallest missing is 2.               |

---

#### **Starter Template (C++)**

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Finds the smallest missing positive integer in an unsorted array.
 * @param nums: A reference to a vector of integers.
 * @return: The smallest missing positive integer.
 */
int findSmallestMissing(vector<int>& nums) {
    // Write your logic here
    
    return 0; 
}

int main() {
    vector<int> test1 = {3, 4, -1, 1};
    vector<int> test2 = {1, 2, 0};
    vector<int> test3 = {7, 8, 9, 11, 12};

    cout << "Test 1: " << findSmallestMissing(test1) << " (Expected: 2)" << endl;
    cout << "Test 2: " << findSmallestMissing(test2) << " (Expected: 3)" << endl;
    cout << "Test 3: " << findSmallestMissing(test3) << " (Expected: 1)" << endl;

    return 0;
}
```

---

#### **Hint**

Think about the **Cyclic Sort** pattern. If the array has size $n$, the smallest missing positive integer must fall
within the range $[1, n+1]$. You can try to place every number `x` at its corresponding index `x-1` (e.g., place `1` at
`index 0`, `2` at `index 1`) using swaps.
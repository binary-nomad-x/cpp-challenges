### Coding Challenge: Two Sum

---

#### **Problem Statement**

Given an array of integers `nums` and an integer `target`, return **indices** of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

Return the answer in any order.

#### **Constraints**

1. **Time Complexity:** Ideally $O(n)$.
2. **Space Complexity:** $O(n)$ for the hash map approach.
3. `2 <= nums.length <= 10^4`
4. `-10^9 <= nums[i] <= 10^9`
5. `-10^9 <= target <= 10^9`

---

#### **Examples**

| Input                  | Target | Output    |
|:-----------------------|:-------|:----------|
| `[2, 7, 11, 15]`       | `9`    | `[0, 1]`  |
| `[3, 2, 4]`            | `6`    | `[1, 2]`  |
| `[3, 3]`               | `6`    | `[0, 1]`  |

---

#### **Starter Template (C++)**

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // Write your logic here
    
    return {};
}

int main() {
    vector<int> test1 = {2, 7, 11, 15};
    vector<int> res1 = twoSum(test1, 9);
    cout << "Test 1: [" << res1[0] << ", " << res1[1] << "] (Expected: [0, 1])" << endl;

    vector<int> test2 = {3, 2, 4};
    vector<int> res2 = twoSum(test2, 6);
    cout << "Test 2: [" << res2[0] << ", " << res2[1] << "] (Expected: [1, 2])" << endl;

    vector<int> test3 = {3, 3};
    vector<int> res3 = twoSum(test3, 6);
    cout << "Test 3: [" << res3[0] << ", " << res3[1] << "] (Expected: [0, 1])" << endl;

    return 0;
}
```

---

#### **Hint**

Use an **unordered_map** (hash map) to store each number's index as you iterate. For each element, check if `target - nums[i]` already exists in the map.

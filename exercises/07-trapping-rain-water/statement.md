### Coding Challenge: Trapping Rain Water

---

#### **Problem Statement**

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

#### **Constraints**

1. **Time Complexity:** Ideally $O(n)$
2. **Space Complexity:** $O(1)$ for the two-pointer approach, $O(n)$ for prefix/suffix arrays
3. `n == height.length`
4. `1 <= n <= 2 * 10^4`
5. `0 <= height[i] <= 10^5`

---

#### **Examples**

| Input                            | Output | Explanation |
|:---------------------------------|:-------|:------------|
| `[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]` | `6`    | 6 units of water trapped |
| `[4, 2, 0, 3, 2, 5]`            | `9`    | 9 units of water trapped |

---

#### **Starter Template (C++)**

```cpp
#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    // Write your logic here

    return 0;
}

int main() {
    vector<int> test1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test 1: " << trap(test1) << " (Expected: 6)" << endl;

    vector<int> test2 = {4, 2, 0, 3, 2, 5};
    cout << "Test 2: " << trap(test2) << " (Expected: 9)" << endl;

    return 0;
}
```

---

#### **Hint**

Use the **two-pointer** technique. Track the maximum height from the left and right. Water trapped at any position is `min(maxLeft, maxRight) - height[i]`.

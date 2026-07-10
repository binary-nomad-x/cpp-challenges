### Coding Challenge: Container With Most Water

---

#### **Problem Statement**

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the $i^{th}$ line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the **most water**.

Return the maximum amount of water a container can store.

**Note:** You may not slant the container.

#### **Constraints**

1. **Time Complexity:** Ideally $O(n)$
2. **Space Complexity:** $O(1)$
3. `n == height.length`
4. `2 <= n <= 10^5`
5. `0 <= height[i] <= 10^4`

---

#### **Examples**

| Input                | Output | Explanation                              |
|:---------------------|:-------|:-----------------------------------------|
| `[1, 8, 6, 2, 5, 4, 8, 3, 7]` | `49`   | Lines at indices 1 and 8 give max area   |
| `[1, 1]`             | `1`    | Only one container possible              |

---

#### **Starter Template (C++)**

```cpp
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    // Write your logic here

    return 0;
}

int main() {
    vector<int> test1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << maxArea(test1) << " (Expected: 49)" << endl;

    vector<int> test2 = {1, 1};
    cout << "Test 2: " << maxArea(test2) << " (Expected: 1)" << endl;

    return 0;
}
```

---

#### **Hint**

Use **two pointers** — one at the start and one at the end. The area is `min(height[l], height[r]) * (r - l)`. Move the pointer pointing to the shorter line inward.

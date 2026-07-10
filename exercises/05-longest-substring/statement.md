### Coding Challenge: Longest Substring Without Repeating Characters

---

#### **Problem Statement**

Given a string `s`, find the length of the **longest substring** without repeating characters.

#### **Constraints**

1. **Time Complexity:** Ideally $O(n)$
2. **Space Complexity:** $O(min(n, m))$ where $m$ is the size of the character set
3. `0 <= s.length <= 5 * 10^4`

---

#### **Examples**

| Input        | Output | Explanation          |
|:-------------|:-------|:---------------------|
| `"abcabcbb"` | `3`    | `"abc"` has length 3 |
| `"bbbbb"`    | `1`    | `"b"` has length 1   |
| `"pwwkew"`   | `3`    | `"wke"` has length 3 |
| `""`         | `0`    | empty string         |

---

#### **Starter Template (C++)**

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    // Write your logic here

    return 0;
}

int main() {
    cout << "Test 1: " << lengthOfLongestSubstring("abcabcbb") << " (Expected: 3)" << endl;
    cout << "Test 2: " << lengthOfLongestSubstring("bbbbb") << " (Expected: 1)" << endl;
    cout << "Test 3: " << lengthOfLongestSubstring("pwwkew") << " (Expected: 3)" << endl;
    cout << "Test 4: " << lengthOfLongestSubstring("") << " (Expected: 0)" << endl;

    return 0;
}
```

---

#### **Hint**

Use the **sliding window** technique with two pointers and an unordered_map to track the last index of each character.
Expand the right pointer and move the left pointer past any duplicate.

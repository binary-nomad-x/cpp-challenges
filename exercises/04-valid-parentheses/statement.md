### Coding Challenge: Valid Parentheses

---

#### **Problem Statement**

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

A string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

#### **Constraints**

1. **Time Complexity:** $O(n)$
2. **Space Complexity:** $O(n)$
3. `1 <= s.length <= 10^4`

---

#### **Examples**

| Input         | Output  |
|:--------------|:--------|
| `"()"`        | `true`  |
| `"()[]{}"`    | `true`  |
| `"(]"`        | `false` |
| `"([)]"`      | `false` |
| `"{[]}"`      | `true`  |

---

#### **Starter Template (C++)**

```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    // Write your logic here

    return false;
}

int main() {
    cout << "Test 1: " << boolalpha << isValid("()") << " (Expected: true)" << endl;
    cout << "Test 2: " << boolalpha << isValid("()[]{}") << " (Expected: true)" << endl;
    cout << "Test 3: " << boolalpha << isValid("(]") << " (Expected: false)" << endl;
    cout << "Test 4: " << boolalpha << isValid("([)]") << " (Expected: false)" << endl;
    cout << "Test 5: " << boolalpha << isValid("{[]}") << " (Expected: true)" << endl;

    return 0;
}
```

---

#### **Hint**

Use a **stack**. Push opening brackets onto the stack. When you see a closing bracket, check if the top of the stack matches it. If not, it's invalid.

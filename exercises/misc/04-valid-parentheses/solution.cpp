#include <iostream>
#include <stack>
#include <string>

using namespace std;

static bool isValid(const string& s) {
    stack<char> st;

    for (char c: s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;

            const char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    cout << "Test 1: " << boolalpha << isValid("()") << " (Expected: true)" << endl;
    cout << "Test 2: " << boolalpha << isValid("()[]{}") << " (Expected: true)" << endl;
    cout << "Test 3: " << boolalpha << isValid("(]") << " (Expected: false)" << endl;
    cout << "Test 4: " << boolalpha << isValid("([)]") << " (Expected: false)" << endl;
    cout << "Test 5: " << boolalpha << isValid("{[]}") << " (Expected: true)" << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

static int lengthOfLongestSubstring(const string &s) {
    unordered_map<char, int> lastIndex;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= left) {
            left = lastIndex[c] + 1;
        }

        lastIndex[c] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    cout << "Test 1: " << lengthOfLongestSubstring("abcabcbb") << " (Expected: 3)" << endl;
    cout << "Test 2: " << lengthOfLongestSubstring("bbbbb") << " (Expected: 1)" << endl;
    cout << "Test 3: " << lengthOfLongestSubstring("pwwkew") << " (Expected: 3)" << endl;
    cout << "Test 4: " << lengthOfLongestSubstring("") << " (Expected: 0)" << endl;

    return 0;
}

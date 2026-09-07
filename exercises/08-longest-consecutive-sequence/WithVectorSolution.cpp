#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

namespace {
    class Solution {
    public:
        static int longestConsecutive(const vector<int> &nums) {
            if (nums.empty())
                return 0;

            unordered_set<int> numbers;
            numbers.reserve(nums.size());
            numbers.insert(nums.begin(), nums.end());

            int longest = 0;

            for (const int num: numbers) {
                if (num != INT_MIN && numbers.find(num - 1) != numbers.end())
                    continue;

                int current = num;
                int length = 1;

                while (current != INT_MAX && numbers.find(current + 1) != numbers.end()) {
                    ++current;
                    ++length;
                }

                longest = max(longest, length);
            }

            return longest;
        }
    };
}

int main() {
    cout << Solution::longestConsecutive({100, 4, 200, 1, 3, 2}) << '\n';
    cout << Solution::longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}) << '\n';
    cout << Solution::longestConsecutive({1, 1, 2, 2, 3}) << '\n';
    cout << Solution::longestConsecutive({}) << '\n';
    cout << Solution::longestConsecutive({5}) << '\n';
}

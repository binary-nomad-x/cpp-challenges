#include <algorithm>
#include <climits>
#include <initializer_list>
#include <iostream>
#include <unordered_set>

using namespace std;

namespace {
    class WithoutVectorSolution {
    public:
        static int longestConsecutive(initializer_list<int> nums) {
            unordered_set<int> s;
            s.reserve(nums.size());
            s.insert(nums.begin(), nums.end());

            int best = 0;

            for (int n: s) {
                if (n > INT_MIN && s.find(n - 1) != s.end())
                    continue;

                int len = 1;
                while (n < INT_MAX && s.find(++n) != s.end())
                    ++len;

                best = max(best, len);
            }

            return best;
        }
    };
}

int main() {
    std::cout << WithoutVectorSolution::longestConsecutive({100, 4, 200, 1, 3, 2}) << '\n';
}

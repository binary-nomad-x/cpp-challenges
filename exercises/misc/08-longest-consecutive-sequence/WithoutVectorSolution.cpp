#include <algorithm>
#include <climits>
#include <initializer_list>
#include <iostream>
#include <unordered_set>

using namespace std;

namespace {
    class WithoutVectorSolution {
    public:
        static int longestConsecutive(const initializer_list<int> nums) {
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
    constexpr auto RESET = "\033[0m";
    constexpr auto CYAN = "\033[36m";
    constexpr auto GREEN = "\033[32m";
    constexpr auto YELLOW = "\033[33m";
    constexpr auto BOLD = "\033[1m";

    const initializer_list<int> input = {100, 4, 200, 1, 3, 2, 6, 0};
    const int result = WithoutVectorSolution::longestConsecutive(input);

    cout << '\n';
    cout << CYAN << BOLD << "╔══════════════════════════════════════╗" << RESET << '\n';
    cout << CYAN << BOLD << "║     Longest Consecutive Sequence     ║" << RESET << '\n';
    cout << CYAN << BOLD << "╚══════════════════════════════════════╝" << RESET << '\n';

    cout << '\n';
    cout << YELLOW << "Input  : " << RESET << "{ ";
    for (const int n: input)
        cout << n << ' ';
    cout << "}\n";

    cout << GREEN << BOLD << "Result : " << RESET << result << '\n';

    cout << '\n';
    cout << GREEN << "✓ Solution completed successfully!" << RESET << '\n';
    cout << '\n';
}

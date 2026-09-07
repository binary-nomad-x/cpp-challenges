#include <iostream>
#include <vector>
using namespace std;

static int trap(const vector<int> &h) {
    if (h.size() < 3) return 0;

    int l = 0, r = static_cast<int>(h.size()) - 1;
    int lm = 0, rm = 0, water = 0;

    while (l < r) {
        if (h[l] <= h[r]) {
            lm = max(lm, h[l]);
            water += lm - h[l++];
        } else {
            rm = max(rm, h[r]);
            water += rm - h[r--];
        }
    }

    return water;
}

int main() {
    const vector<vector<int> > tests = {
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
        {4, 2, 0, 3, 2, 5},
        {3, 0, 2, 0, 4},
        {1, 2, 3},
        {3, 2, 1},
        {}
    };

    const vector<int> expected = {6, 9, 7, 0, 0, 0};

    cout << "\033[1;36m╔════════════════════════════════════╗\033[0m\n";
    cout << "\033[1;36m║       Trapping Rain Water 💧       ║\033[0m\n";
    cout << "\033[1;36m╚════════════════════════════════════╝\033[0m\n\n";

    for (size_t i = 0; i < tests.size(); ++i) {
        const int result = trap(tests[i]);
        const bool pass = result == expected[i];

        cout << "Test " << i + 1 << "  "
                << (pass ? "\033[1;32m✓ PASS\033[0m" : "\033[1;31m✗ FAIL\033[0m")
                << "  | Result: " << result
                << " | Expected: " << expected[i] << '\n';
    }

    return 0;
}

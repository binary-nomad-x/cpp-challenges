#include <iostream>
#include <vector>

using namespace std;

static int maxArea(const vector<int> &h) {
    int l = 0, r = static_cast<int>(h.size()) - 1, best = 0;

    while (l < r) {
        const int hl = h[l], hr = h[r];
        const int area = (hl < hr ? hl : hr) * (r - l);

        if (area > best)
            best = area;

        hl < hr ? ++l : --r;
    }

    return best;
}

int main() {
    cout << maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << '\n';
    cout << maxArea({1, 1}) << '\n';
}

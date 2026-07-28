#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int maxArea(const vector<int> &height) {
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int maxWater = 0;

    while (left < right) {
        maxWater = max(
            maxWater,
            min(height[left], height[right]) * (right - left)
        );

        if (height[left] <= height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return maxWater;
}

int main() {
    cout << maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << '\n'; // 49
    cout << maxArea({1, 1}) << '\n'; // 1
}

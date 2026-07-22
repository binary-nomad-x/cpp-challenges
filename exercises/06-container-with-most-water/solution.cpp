#include <iostream>
#include <vector>

using namespace std;

static int maxArea(const vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        const int h = min(height[left], height[right]);
        const int w = right - left;
        maxWater = max(maxWater, h * w);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }

    }

    return maxWater;
}

int main() {
    const vector<int> test1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << maxArea(test1) << " (Expected: 49)" << endl;

    const vector<int> test2 = {1, 1};
    cout << "Test 2: " << maxArea(test2) << " (Expected: 1)" << endl;

    return 0;
}

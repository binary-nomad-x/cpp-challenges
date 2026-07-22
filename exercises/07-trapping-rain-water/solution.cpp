#include <iostream>
#include <vector>

using namespace std;

static int trap(const vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int total = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                total += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                total += rightMax - height[right];
            }
            right--;
        }
    }

    return total;
}

int main() {
    vector<int> test1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test 1: " << trap(test1) << " (Expected: 6)" << endl;

    vector<int> test2 = {4, 2, 0, 3, 2, 5};
    cout << "Test 2: " << trap(test2) << " (Expected: 9)" << endl;

    return 0;
}

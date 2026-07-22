#include <iostream>
#include <vector>

using namespace std;

/**
 * Finds the smallest missing positive integer in an unsorted array.
 * @param nums: A reference to a vector of integers.
 * @return: The smallest missing positive integer.
 */
static int findSmallestMissing(vector<int> &nums) {
    const int n = static_cast<int>(nums.size());

    int i = 0;
    while (i < n) {
        const int correctIndex = nums[i] - 1;

        if (nums[i] > 0 &&
            nums[i] <= n &&
            nums[i] != nums[correctIndex]) {
            swap(nums[i], nums[correctIndex]);
        } else {
            ++i;
        }
    }

    for (int j = 0; j < n; ++j) {
        if (nums[j] != j + 1)
            return j + 1;
    }

    return n + 1;
}

int main() {
    vector<int> test1 = {3, 4, -1, 1};
    vector<int> test2 = {1, 2, 0};
    vector<int> test3 = {7, 8, 9, 11, 12};
    vector<int> test4 = {1, 1, 1};

    cout << "Test 1: " << findSmallestMissing(test1) << " (Expected: 2)" << endl;
    cout << "Test 2: " << findSmallestMissing(test2) << " (Expected: 3)" << endl;
    cout << "Test 3: " << findSmallestMissing(test3) << " (Expected: 1)" << endl;
    cout << "Test 4: " << findSmallestMissing(test4) << " (Expected: 2)" << endl;

    return 0;
}

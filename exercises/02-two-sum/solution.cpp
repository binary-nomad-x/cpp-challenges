#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(const vector<int> &nums, const int target) {
    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;
    }

    return {};
}

int main() {
    const vector<int> test1 = {2, 7, 11, 15};
    const vector<int> res1 = twoSum(test1, 9);
    cout << "Test 1: [" << res1[0] << ", " << res1[1] << "] (Expected: [0, 1])" << endl;

    const vector<int> test2 = {3, 2, 4};
    const vector<int> res2 = twoSum(test2, 6);
    cout << "Test 2: [" << res2[0] << ", " << res2[1] << "] (Expected: [1, 2])" << endl;

    const vector<int> test3 = {3, 3};
    const vector<int> res3 = twoSum(test3, 6);
    cout << "Test 3: [" << res3[0] << ", " << res3[1] << "] (Expected: [0, 1])" << endl;

    return 0;
}

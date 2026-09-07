#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

namespace {
    class Solution {
    public:
        /**
     * Find the length of the longest consecutive elements sequence.
     *
     * Approach: Use a hash set for O(1) lookups.
     *
     * Key Insight: Only start counting from the smallest number in a sequence.
     * A number is the start of a sequence if (num - 1) does NOT exist in the set.
     *
     * Time Complexity: O(n) - Each element is visited at most twice
     * Space Complexity: O(n) - Hash set storage
     *
     * @param nums Vector of integers (unsorted, may contain duplicates)
     * @return Length of the longest consecutive sequence
     */
        static int longestConsecutive(const vector<int> &nums) {
            // Edge case: empty array
            if (nums.empty()) {
                return 0;
            }

            // Step 1: Insert all numbers into a hash set for O(1) lookups
            // Using unordered_set for average O(1) time complexity
            unordered_set<int> numSet(nums.begin(), nums.end());

            int longestStreak = 0;

            // Step 2: Iterate through each unique number
            for (const int num: numSet) {
                // CRITICAL OPTIMIZATION:
                // Only start counting if this is the START of a sequence
                // If (num - 1) exists, this number is NOT the start,
                // so skip it - it will be counted when we reach the actual start
                if (numSet.find(num - 1) == numSet.end()) {
                    // Found the start of a sequence!
                    int currentNum = num;
                    int currentStreak = 1;

                    // Step 3: Count how many consecutive numbers exist
                    // Keep checking num+1, num+2, num+3, ...
                    while (numSet.find(currentNum + 1) != numSet.end()) {
                        currentNum++;
                        currentStreak++;
                    }

                    // Step 4: Update the longest streak found so far
                    longestStreak = max(longestStreak, currentStreak);
                }
            }

            return longestStreak;
        }
    };
}

namespace {
    // Alternative implementation with detailed comments for better understanding
    class SolutionDetailed {
    public:
        static int longestConsecutive(const vector<int> &nums) {
            // Handle empty input
            if (nums.empty()) {
                return 0;
            }

            // Use unordered_set for O(1) average case lookups
            // This removes duplicates automatically
            unordered_set<int> numbers;
            for (int num: nums) {
                numbers.insert(num);
            }

            int maxLength = 0;

            // Iterate through each unique number
            for (const int num: numbers) {
                // IMPORTANT:
                // We only start a new sequence from the smallest number
                // If num-1 exists, then num is part of a larger sequence
                // and will be counted when we reach the actual start
                if (numbers.find(num - 1) == numbers.end()) {
                    // This is the start of a sequence
                    int current = num;
                    int length = 0;

                    // Count consecutive numbers: num, num+1, num+2, ...
                    while (numbers.find(current) != numbers.end()) {
                        length++;
                        current++;
                    }

                    // Update maximum length
                    maxLength = max(maxLength, length);
                }
            }

            return maxLength;
        }
    };
}

#include <iostream>

int main() {
    // Test Case 1
    const vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test 1: " << Solution::longestConsecutive(nums1) << endl; // Expected: 4

    // Test Case 2
    const vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test 2: " << Solution::longestConsecutive(nums2) << endl; // Expected: 9

    // Test Case 3
    const vector<int> nums3 = {1, 1, 2, 2, 3};
    cout << "Test 3: " << Solution::longestConsecutive(nums3) << endl; // Expected: 3

    // Test Case 4: Empty array
    const vector<int> nums4 = {};
    cout << "Test 4: " << Solution::longestConsecutive(nums4) << endl; // Expected: 0

    // Test Case 5: Single element
    const vector<int> nums5 = {5};
    cout << "Test 5: " << Solution::longestConsecutive(nums5) << endl; // Expected: 1

    return 0;
}

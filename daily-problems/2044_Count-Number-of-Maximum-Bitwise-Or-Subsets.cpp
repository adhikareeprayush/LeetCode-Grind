// #Maximum Bitwise OR Subset
// Date: 2024/10/17 Thursday

// Problem Statement:
// Given an integer array `nums`, find the maximum possible bitwise OR of a subset of `nums` 
// and return the number of different non-empty subsets with the maximum bitwise OR.

// Approach:
// 1. First, compute the maximum bitwise OR across all elements of the array.
// 2. Then, iterate through all possible subsets and count how many have this maximum OR value.
// 3. Use a backtracking method to explore each subset and compute their bitwise OR values.

// Time Complexity:
// The time complexity is O(2^n), where n is the length of `nums` since we need to check all subsets.

// Space Complexity:
// The space complexity is O(n) for the recursion stack and storing intermediate results.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int maxOr;  // To store the maximum OR value
    int count;  // To count the number of subsets with the maximum OR

    // Helper function to explore subsets
    void backtrack(vector<int>& nums, int index, int currentOr) {
        // If we have processed all elements
        if (index == nums.size()) {
            // Check if the OR of this subset equals the maximum OR
            if (currentOr == maxOr) {
                count++;  // Count this subset
            }
            return;
        }

        // Include the current element in the subset
        backtrack(nums, index + 1, currentOr | nums[index]);

        // Exclude the current element from the subset
        backtrack(nums, index + 1, currentOr);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        maxOr = 0;
        count = 0;

        // Calculate the maximum possible bitwise OR for the entire array
        for (int num : nums) {
            maxOr |= num;
        }

        // Start backtracking from index 0 with an initial OR value of 0
        backtrack(nums, 0, 0);

        return count;  // Return the number of subsets with the maximum bitwise OR
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {3, 1};
    cout << "Number of subsets with max OR for nums1: " << solution.countMaxOrSubsets(nums1) << endl;  // Output: 2

    // Example 2
    vector<int> nums2 = {2, 2, 2};
    cout << "Number of subsets with max OR for nums2: " << solution.countMaxOrSubsets(nums2) << endl;  // Output: 7

    // Example 3
    vector<int> nums3 = {3, 2, 1, 5};
    cout << "Number of subsets with max OR for nums3: " << solution.countMaxOrSubsets(nums3) << endl;  // Output: 6

    return 0;
}

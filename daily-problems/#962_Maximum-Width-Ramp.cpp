// #962 Maximum Width Ramp
// Date: 2024/10/10 Thursday

// Problem Statement:
// A ramp in an integer array nums is defined as a pair (i, j) where i < j and nums[i] <= nums[j].
// The width of such a ramp is j - i. The task is to return the maximum width of a ramp in nums. 
// If no ramp exists, return 0.

// Approach:
// 1. First, create a list of pairs where each pair contains the index and the corresponding value 
//    from the nums array.
// 2. Sort the list of pairs based on the values in nums. If two values are equal, sort by the index.
// 3. Iterate through the sorted list of pairs while maintaining the minimum index encountered so far.
// 4. For each pair, calculate the width by subtracting the minimum index from the current index. 
//    Update the maximum width whenever a larger width is found.
// 5. Return the maximum width at the end of the iteration.

// Steps:
// 1. Create a list of index-value pairs from the nums array.
// 2. Sort this list by the values in nums.
// 3. Track the smallest index seen so far and iterate through the list to compute the maximum width.
// 4. Return the maximum width of the ramp found.

// Time Complexity:
// Sorting the array of index-value pairs takes O(n log n), where n is the size of the nums array.
// Iterating through the sorted array takes O(n). Therefore, the overall time complexity is O(n log n).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to calculate the maximum width ramp
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> idx_value;  // List to store index-value pairs
        
        // Populate the list with index and value pairs
        for (int i = 0; i < n; ++i) {
            idx_value.push_back({i, nums[i]});
        }

        // Sort the list based on values in nums, and by index if values are the same
        sort(idx_value.begin(), idx_value.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second || (a.second == b.second && a.first < b.first);
        });

        // Initialize minimum index and max width ramp
        int min_index = idx_value[0].first;
        int max_width = 0;

        // Iterate through the sorted list to find the maximum width ramp
        for (int i = 1; i < n; ++i) {
            int current_index = idx_value[i].first;
            max_width = max(max_width, current_index - min_index);
            min_index = min(min_index, current_index);
        }

        return max_width;  // Return the maximum width found
    }
};

int main() {
    // Example 1
    Solution solution;
    vector<int> nums1 = {6, 0, 8, 2, 1, 5};
    cout << "Maximum width ramp: " << solution.maxWidthRamp(nums1) << endl;  // Output: 4

    // Example 2
    vector<int> nums2 = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    cout << "Maximum width ramp: " << solution.maxWidthRamp(nums2) << endl;  // Output: 7

    return 0;
}

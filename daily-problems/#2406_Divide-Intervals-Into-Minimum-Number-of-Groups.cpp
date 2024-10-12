// #2406 Divide Intervals Into Minimum Number of Groups
// Date: 2024/10/12 Saturday

// Problem Statement:
// You are given a 2D integer array intervals where each interval represents an inclusive range.
// You need to divide the intervals into the minimum number of groups such that no two intervals in the same group overlap.


// Approach:
// 1. Treat the problem as an interval scheduling problem, where you keep track of how many intervals overlap at any point.
// 2. For each interval, track both its start and end events.
// 3. Sort these events by time. For start events, increment the count of active intervals, and for end events, decrement it.
// 4. The maximum count of active intervals at any time gives the minimum number of groups needed.

// Time Complexity:
// Sorting the events takes O(n log n), and processing the events takes O(n), so the overall time complexity is O(n log n).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        
        // Separate out the start and end events
        for (auto& interval : intervals) {
            events.push_back({interval[0], 1});   // Starting an interval adds an active group
            events.push_back({interval[1] + 1, -1}); // Ending an interval reduces an active group
        }
        
        // Sort events by time. If times are the same, end events come first to avoid over-counting.
        sort(events.begin(), events.end());

        int maxGroups = 0, currentGroups = 0;

        // Process events
        for (auto& event : events) {
            currentGroups += event.second;   // Adjust the number of active groups
            maxGroups = max(maxGroups, currentGroups);  // Track the maximum overlap at any time
        }

        return maxGroups;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> intervals1 = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    cout << "Minimum number of groups: " << solution.minGroups(intervals1) << endl;  // Output: 3

    // Example 2
    vector<vector<int>> intervals2 = {{1, 3}, {5, 6}, {8, 10}, {11, 13}};
    cout << "Minimum number of groups: " << solution.minGroups(intervals2) << endl;  // Output: 1

    return 0;
}

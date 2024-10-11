// #1942 The Number of the Smallest Unoccupied Chair
// Date: 2024/10/10 Thursday

// Problem Statement:
// There is a party where n friends are attending. Each friend arrives and sits in the smallest unoccupied chair.
// When a friend leaves, their chair becomes available.
// Given the arrival and leaving times of each friend, return the chair number that a specific friend will sit on.

// Approach:
// 1. Sort the friends based on their arrival times.
// 2. Use a priority queue (min-heap) to keep track of the smallest unoccupied chairs.
// 3. Use another priority queue to keep track of when chairs become free based on friends' leaving times.
// 4. When a friend arrives, assign them the smallest unoccupied chair. When a friend leaves, mark their chair as available.
// 5. Find and return the chair number of the target friend.

// Time Complexity:
// The time complexity is O(n log n) because sorting the friends and managing the priority queues takes O(n log n).

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> events;  // To store arrival and leaving events
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], i});  // arrival event
        }

        // Sort events based on arrival times
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> availableChairs;  // Min-heap for available chairs
        for (int i = 0; i < n; ++i) availableChairs.push(i);  // Initially all chairs are available

        // Min-heap to store leaving times, {leavingTime, chairNumber}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

        vector<int> assignedChair(n, -1);  // To store the chair assigned to each friend

        // Iterate over the sorted events
        for (const auto& event : events) {
            int arrivalTime = event.first;
            int friendIndex = event.second;

            // Free up chairs of friends who have left by the time of this arrival
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrivalTime) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            // Assign the smallest available chair to the arriving friend
            int chair = availableChairs.top();
            availableChairs.pop();
            assignedChair[friendIndex] = chair;

            // If this is the target friend, return their chair number
            if (friendIndex == targetFriend) {
                return chair;
            }

            // Push this friend's leaving time and chair number to the occupied heap
            occupiedChairs.push({times[friendIndex][1], chair});
        }

        return -1;  // This should never be reached
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> times1 = {{1, 4}, {2, 3}, {4, 6}};
    int targetFriend1 = 1;
    cout << "Chair for target friend: " << solution.smallestChair(times1, targetFriend1) << endl;  // Output: 1

    // Example 2
    vector<vector<int>> times2 = {{3, 10}, {1, 5}, {2, 6}};
    int targetFriend2 = 0;
    cout << "Chair for target friend: " << solution.smallestChair(times2, targetFriend2) << endl;  // Output: 2

    return 0;
}

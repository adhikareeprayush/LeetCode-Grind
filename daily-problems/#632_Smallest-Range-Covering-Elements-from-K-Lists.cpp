#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queue to store (current value, list index, element index)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        int k = nums.size();  // Number of lists
        int maxVal = INT_MIN;  // To track the maximum value in the current window
        
        // Insert the first element of each list into the priority queue
        for (int i = 0; i < k; ++i) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }
        
        // Initialize the smallest range with large values
        int rangeStart = 0, rangeEnd = INT_MAX;
        
        // Process the heap
        while (true) {
            // Get the smallest element from the heap
            pair<int, pair<int, int>> topElement = pq.top();
            pq.pop();
            
            int minVal = topElement.first;
            int listIndex = topElement.second.first;
            int elementIndex = topElement.second.second;
            
            // Update the range if the current range is smaller
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }
            
            // Move to the next element in the same list
            if (elementIndex + 1 < nums[listIndex].size()) {
                int nextVal = nums[listIndex][elementIndex + 1];
                pq.push({nextVal, {listIndex, elementIndex + 1}});
                maxVal = max(maxVal, nextVal);
            } else {
                // If any list is exhausted, we stop
                break;
            }
        }
        
        return {rangeStart, rangeEnd};
    }
};

int main() {
    Solution solution;
    
    // Example test case
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    
    vector<int> result = solution.smallestRange(nums);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;  // Output: [20, 24]
    
    return 0;
}

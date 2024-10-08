// #1963 Minimum Number of Swaps to Make the String Balanced
// Date: 2024/10/08 Tuesday

// Problem Statement
// You are given a string `s` consisting of square brackets.
// You need to find the minimum number of adjacent swaps required to make the string balanced.
// A balanced string is defined as a string where every opening bracket '[' has a corresponding closing bracket ']'.
// Return the minimum number of swaps needed to balance the string.

// Concepts Used
// 1. Imbalance Counting
// 2. Maximum Imbalance Tracking

// Steps:
// 1. Iterate through the string and track the imbalance (i.e., how many more closing brackets are needed).
// 2. If an opening bracket '[' is encountered, reduce the imbalance count.
// 3. If a closing bracket ']' is encountered, increase the imbalance count.
// 4. Keep track of the maximum imbalance encountered.
// 5. To balance the string, we need half the maximum imbalance (rounded up) swaps.

// Time Complexity Analysis
// The solution iterates through the string once, so the time complexity is O(n), where n is the length of the string.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;  // Tracks how many more closing brackets are needed
        int maxImbalance = 0;  // Tracks the maximum imbalance encountered

        for (char c : s) {
            if (c == '[') {
                imbalance--;  // Opening bracket reduces the need for a closing one
            } else {
                imbalance++;  // Closing bracket increases the need for an opening one
            }

            // Keep track of the maximum imbalance seen
            maxImbalance = max(maxImbalance, imbalance);
        }

        // We need half the maximum imbalance (rounded up) swaps to balance the string
        return (maxImbalance + 1) / 2;
    }
};

int main() {
    Solution solution;
    string s = "][][";  // Input string
    cout << solution.minSwaps(s) << endl;  // Output the minimum number of swaps
    return 0;
}

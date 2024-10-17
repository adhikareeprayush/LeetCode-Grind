// #670 Maximum Swap
// Date: 2024/10/17 Thursday

// Problem Statement:
// You are given an integer `num`. You can swap two digits at most once to get the maximum valued number.
// Return the maximum valued number you can get after one swap.

// Approach:
// 1. Convert the number to a string for easy manipulation of individual digits.
// 2. For each digit, look at the digits to the right and find the largest possible digit to swap with.
// 3. Perform the swap to maximize the value of the number.
// 4. Return the integer form of the modified string after the swap.

// Time Complexity:
// The time complexity is O(n), where n is the number of digits in `num`.
// We traverse the digits and find the best possible swap in linear time.

// Space Complexity:
// The space complexity is O(n), where n is the number of digits, due to the conversion of the number to a string.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num); // Convert the integer to a string
        int n = numStr.size();
        vector<int> lastIndex(10, -1); // To store the last occurrence of each digit

        // Fill lastIndex with the last occurrence of each digit in the number
        for (int i = 0; i < n; ++i) {
            lastIndex[numStr[i] - '0'] = i;
        }

        // Try to find the best place to swap digits
        for (int i = 0; i < n; ++i) {
            // Check for a larger digit on the right of the current digit
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (lastIndex[d] > i) {
                    // Swap the current digit with the larger one found on the right
                    swap(numStr[i], numStr[lastIndex[d]]);
                    return stoi(numStr); // Convert back to integer and return
                }
            }
        }

        return num; // If no swap improves the value, return the original number
    }
};

int main() {
    Solution solution;

    // Example 1
    int num1 = 2736;
    cout << "Max swap of " << num1 << " is: " << solution.maximumSwap(num1) << endl; // Output: 7236

    // Example 2
    int num2 = 9973;
    cout << "Max swap of " << num2 << " is: " << solution.maximumSwap(num2) << endl; // Output: 9973

    return 0;
}

// #2938 Separate Black and White Balls
// Date: 2024/10/15 Tuesday

// Problem Statement:
// Given a 0-indexed binary string s of length n, where '1' represents a black ball and '0' 
// represents a white ball, calculate the minimum number of steps needed to group all black 
// balls to the right and all white balls to the left. In each step, you can choose two 
// adjacent balls and swap them.

// Approach:
// 1. Iterate through the string from left to right.
// 2. Count the number of black balls encountered.
// 3. For each white ball, add the current count of black balls to the total steps.
// 4. The final sum represents the minimum number of steps needed to group all black balls 
//    to the right.

// Steps:
// 1. Initialize variables for steps and black ball count.
// 2. Iterate through each character in the string:
//    - If the character is '1' (black ball), increment the black ball count.
//    - If the character is '0' (white ball), add the current black ball count to steps.
// 3. Return the total number of steps.

// Time Complexity:
// The time complexity of this approach is O(n), where n is the length of the input string s.
// We iterate through the string once, performing constant-time operations for each character.

// Space Complexity:
// The space complexity is O(1) as we only use a constant amount of extra space regardless 
// of the input size.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to calculate the minimum number of steps to group balls
    int minimumSteps(string s) {
        int n = s.length();
        long long steps = 0;
        int black_count = 0;
        
        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                // Count the number of black balls
                black_count++;
            } else {
                // For each white ball, add the number of black balls to its right
                steps += black_count;
            }
        }
        
        return steps;
    }
};

int main() {
    // Example test cases
    Solution solution;
    string s1 = "101";
    string s2 = "100";
    string s3 = "0111";

    cout << solution.minimumSteps(s1) << endl; // Output: 1
    cout << solution.minimumSteps(s2) << endl; // Output: 2
    cout << solution.minimumSteps(s3) << endl; // Output: 0

    return 0;
}
// #2696 Minimum Length of String After Removing Pairs
// Date: 2024/10/05 Saturday

// Problem Statement:
// You are given a string 's' containing the characters 'A', 'B', 'C', and 'D'. 
// You need to remove adjacent pairs of "AB" and "CD" iteratively until no more pairs can be removed. 
// The goal is to return the minimum length of the string after all possible removals.

// Approach:
// Use a stack to track the characters while iterating through the string.
// Push characters into the stack if the current character and the top of the stack don't form a removable pair.
// If they do form a pair ("AB" or "CD"), pop the top character from the stack and do not push the current character.
// At the end of the process, the size of the stack will represent the minimized length of the string.

// Steps:
// 1. Initialize an empty stack to hold characters.
// 2. Traverse the input string character by character.
// 3. If the stack is not empty and the current character forms a pair with the top character, pop the stack.
// 4. Otherwise, push the current character onto the stack.
// 5. Return the size of the stack, which is the minimized string length.

// Time Complexity:
// The time complexity is O(n), where n is the length of the input string `s`.
// This is because we traverse the string once, and each character is pushed or popped from the stack at most once.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;  // Stack to track characters
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                // If stack is empty, push the current character
                st.push(s[i]);
            } else {
                // Check if the current character forms a removable pair with the top of the stack
                if ((s[i] == 'B' && st.top() == 'A') || (s[i] == 'D' && st.top() == 'C')) {
                    // If it's a removable pair, pop the top of the stack
                    st.pop();
                } else {
                    // Otherwise, push the current character
                    st.push(s[i]);
                }
            }
        }

        // The size of the stack represents the minimized length of the string
        return st.size();
    }
};

int main() {
    Solution solution;
    string s = "ABFCACDB";  // Input string
    cout << solution.minLength(s) << endl;  // Output the minimized length of the string
    return 0;
}

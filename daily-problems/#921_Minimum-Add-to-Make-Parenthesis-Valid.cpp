// #921 Minimum Add to Make Parentheses Valid
// Date: 2024/10/09 Monday

// Problem Statement:
// Given a string `s` consisting of parentheses `(` and `)`, this function calculates the minimum 
// number of parentheses that must be added to make `s` valid. A string is considered valid if 
// every opening parenthesis has a corresponding closing parenthesis and the parentheses are 
// closed in the correct order. 

// Approach:
// 1. Use a stack to keep track of unmatched opening parentheses.
// 2. Iterate through each character in the string:
//    - If the character is an opening parenthesis `(`, push it onto the stack.
//    - If it is a closing parenthesis `)`, check if there is a corresponding opening 
//      parenthesis in the stack. If yes, pop it; otherwise, add it to the stack.
// 3. The size of the stack at the end will represent the number of unmatched parentheses, 
//    which is the result.

// Steps:
// 1. Initialize an empty stack to store unmatched parentheses.
// 2. Loop through each character in the string:
//    - If the stack is empty or the character is an opening parenthesis, push it onto the stack.
//    - If the character is a closing parenthesis and the top of the stack is an opening 
//      parenthesis, pop the stack.
//    - Otherwise, push the closing parenthesis onto the stack.
// 3. Return the size of the stack as it represents the minimum number of parentheses needed 
//    to make the string valid.

// Time Complexity:
// The time complexity of this approach is O(n), where n is the length of the input string `s`. 
// This is because we iterate through the string once, and each operation (push and pop) on the 
// stack takes O(1) time. 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Function to calculate the minimum number of parentheses to add for validity
    int minAddToMakeValid(string s) {
        stack<char> st;  // Stack to store unmatched parentheses
        int n = s.length(); 
        
        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);  // Push if stack is empty
            } else {
                // If top of stack is an opening parenthesis and current is a closing parenthesis
                if ((st.top() == '(') && (s[i] == ')')) {
                    st.pop();  // Pop the matching pair
                } else {
                    st.push(s[i]);  // Push current character
                }
            }
        }
        return st.size();  // Return the size of the stack
    }
};

int main() {
    // Example test case
    Solution solution;
    string s = "()))((";

    cout << solution.minAddToMakeValid(s) << endl; // Output: 4

    return 0;
}

// #2940 Longest Happy String
// Date: 2024/10/15 Tuesday

// Problem Statement:
// A string s is called happy if it satisfies the following conditions:
// 1. s only contains the letters 'a', 'b', and 'c'.
// 2. s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// 3. s contains at most 'a' occurrences of the letter 'a'.
// 4. s contains at most 'b' occurrences of the letter 'b'.
// 5. s contains at most 'c' occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string.
// If there are multiple longest happy strings, return any of them.
// If there is no such string, return the empty string "".

// Approach:
// 1. Use a greedy approach to build the string character by character.
// 2. Maintain the counts of 'a', 'b', and 'c', ensuring we don't place 
//    more than two consecutive occurrences of any character.
// 3. Select the character with the highest remaining count, ensuring it
//    doesn't violate the "no three consecutive" rule.
// 4. Repeat the process until no more valid characters can be added.

// Time Complexity:
// The time complexity is O(a + b + c), where a, b, and c are the input counts.
// We will build the string up to a total length of a + b + c.

// Space Complexity:
// The space complexity is O(1) since we're only using a fixed amount of extra space
// aside from the result string.

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    // Function to generate the longest happy string
    string longestHappyString(int a, int b, int c) {
        // Max-heap to store the characters and their counts
        priority_queue<pair<int, char>> pq;
        
        // Add the characters with their counts to the heap if they are non-zero
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = ""; // Store the resulting happy string
        
        while (!pq.empty()) {
            // Pop the character with the highest remaining count
            auto first = pq.top(); pq.pop();
            
            // If the last two characters in the result are the same as 'first',
            // we need to use the next most frequent character (if available)
            if (result.size() >= 2 && result.back() == first.second && result[result.size()-2] == first.second) {
                if (pq.empty()) break; // No other characters to use, so stop
                
                // Get the second most frequent character
                auto second = pq.top(); pq.pop();
                
                // Add the second character to the result
                result += second.second;
                
                // Decrease its count and push it back if it still has remaining occurrences
                if (--second.first > 0) pq.push(second);
                
                // Push the first character back to try again later
                pq.push(first);
            } else {
                // Otherwise, we can safely add 'first' to the result
                result += first.second;
                
                // Decrease its count and push it back if it still has remaining occurrences
                if (--first.first > 0) pq.push(first);
            }
        }
        
        return result; // Return the longest happy string
    }
};

int main() {
    // Example test cases
    Solution solution;
    
    // Test case 1
    int a1 = 1, b1 = 1, c1 = 7;
    cout << solution.longestHappyString(a1, b1, c1) << endl; // Output: "ccaccbcc" or similar
    
    // Test case 2
    int a2 = 7, b2 = 1, c2 = 0;
    cout << solution.longestHappyString(a2, b2, c2) << endl; // Output: "aabaa"
    
    // Test case 3
    int a3 = 0, b3 = 0, c3 = 0;
    cout << solution.longestHappyString(a3, b3, c3) << endl; // Output: ""
    
    return 0;
}

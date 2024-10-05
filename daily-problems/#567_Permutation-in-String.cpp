// #567 Permutation in String
// Date: 2024/10/05 Saturday


// Problem Statement:
// You are given two strings s1 and s2. You need to return true if a permutation of s1 is a substring of s2. Otherwise, return false.

// Approach:
// Use a sliding window and frequency count to track the characters in a window of size s1 in s2.
// First, initialize frequency maps for both s1 and the first window in s2.
// Slide the window over s2 and check if the updated window matches the frequency of s1.
// If a matching window is found, return true. If no match is found, return false.

// Steps:
// Initialize frequency maps for s1 and the first len1 characters of s2.
// Check if the initial window of s2 matches the frequency map of s1.
// Slide the window across s2 and update the frequency map.
// If a match is found, return true. Otherwise, return false.

// Time Complexity:
// Initializing the frequency map takes O(len1).
// Sliding through the string s2 takes O(len2).
// The total time complexity is O(len2), where len2 is the length of s2.

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();

        // If s1 is longer than s2, a permutation of s1 can't be a substring of s2
        if (len1 > len2) return false;

        // Frequency maps for s1 and the current sliding window in s2
        unordered_map<char, int> s1_map, sliding_window;

        // Initialize the frequency maps with the first window of s2
        for (int i = 0; i < len1; i++) {
            s1_map[s1[i]]++;
            sliding_window[s2[i]]++;
        }

        // Check if the initial window matches
        if (sliding_window == s1_map) return true;

        // Sliding window over the rest of s2
        for (int i = len1; i < len2; i++) {
            // Add the new character to the window
            sliding_window[s2[i]]++;

            // Remove the old character that's out of the window
            char old_char = s2[i - len1];
            if (sliding_window[old_char] == 1) {
                sliding_window.erase(old_char);
            } else {
                sliding_window[old_char]--;
            }

            // Check if the updated window matches s1_map
            if (sliding_window == s1_map) {
                return true;
            }
        }

        // If no matching permutation is found
        return false;
    }
};

int main() {
    Solution solution;
    string s1 = "ab";
    string s2 = "eidbaooo";

    if (solution.checkInclusion(s1, s2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

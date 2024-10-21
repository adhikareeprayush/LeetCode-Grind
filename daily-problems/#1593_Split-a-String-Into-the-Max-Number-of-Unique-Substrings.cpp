// #1593: Maximum Number of Unique Substrings
// Date: 2024/10/21 Monday

// Problem Statement:
// Given a string s, return the maximum number of unique substrings that the given string can be split into.
// You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string.
// However, you must split the substrings such that all of them are unique.
// A substring is a contiguous sequence of characters within a string.

// Approach:
// 1. Use a greedy approach with a set to keep track of used substrings.
// 2. Iterate through the string, always trying to find the longest possible unique substring.
// 3. Add the unique substring to the set and continue with the rest of the string.
// 4. The size of the set at the end gives the maximum number of unique substrings.

// Time Complexity: O(n^2), where n is the length of the string.
// Space Complexity: O(n^2) for storing substrings in the set.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> used;
        return split(s, 0, used);
    }

private:
    int split(const string& s, int start, unordered_set<string>& used) {
        if (start == s.length()) {
            return 0;
        }
        
        int maxSplits = 0;
        for (int i = start; i < s.length(); ++i) {
            string substr = s.substr(start, i - start + 1);
            if (used.find(substr) == used.end()) {
                used.insert(substr);
                int splits = 1 + split(s, i + 1, used);
                maxSplits = max(maxSplits, splits);
                used.erase(substr);
            }
        }
        
        return maxSplits;
    }
};

int main() {
    Solution solution;

    // Example 1
    string s1 = "ababccc";
    cout << "Input: s = \"" << s1 << "\"\n";
    cout << "Output: " << solution.maxUniqueSplit(s1) << "\n\n";

    // Example 2
    string s2 = "aba";
    cout << "Input: s = \"" << s2 << "\"\n";
    cout << "Output: " << solution.maxUniqueSplit(s2) << "\n\n";

    // Example 3
    string s3 = "aa";
    cout << "Input: s = \"" << s3 << "\"\n";
    cout << "Output: " << solution.maxUniqueSplit(s3) << "\n\n";

    // Failing test case
    string s4 = "wwwzfvedwfvhsww";
    cout << "Input: s = \"" << s4 << "\"\n";
    cout << "Output: " << solution.maxUniqueSplit(s4) << "\n";

    return 0;
}
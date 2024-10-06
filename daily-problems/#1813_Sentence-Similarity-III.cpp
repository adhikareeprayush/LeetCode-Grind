// #1813 Sentence Similarity III
// Date: 2024/10/06 Sunday

// Problem Statement:
// You are given two strings `sentence1` and `sentence2`, both representing sentences composed of words. 
// The sentences are considered similar if it is possible to insert an arbitrary sentence inside one of 
// these sentences such that the two sentences become equal. Return `true` if `sentence1` and `sentence2` 
// are similar, otherwise return `false`.

// Approach:
// 1. Split both sentences into arrays of words using space as the delimiter.
// 2. Compare words from the beginning of both arrays (prefix) and words from the end (suffix).
// 3. If the total number of matching prefix and suffix words is greater than or equal to the length 
//    of the shorter sentence, return `true`; otherwise, return `false`.

// Steps:
// 1. Split `sentence1` and `sentence2` into vectors of words.
// 2. Count the number of matching words from the beginning of both sentences.
// 3. Count the number of matching words from the end of both sentences.
// 4. Return true if the sum of matching prefix and suffix words is greater than or equal to the length of 
//    the shorter sentence, else return false.

// Time Complexity:
// Splitting the sentences takes O(n), where n is the total number of characters in the sentences.
// Comparing the prefix and suffix takes O(min(len1, len2)), where len1 and len2 are the number of words 
// in `sentence1` and `sentence2`. 
// Overall time complexity is O(n), where n is the total number of words in both sentences.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    // Main function to check if the two sentences are similar
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Step 1: Split the sentences into vectors of words
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);

        int len1 = words1.size();
        int len2 = words2.size();

        int i = 0, j = 0;

        // Step 2: Count matching words from the beginning (prefix)
        while(i < len1 && i < len2 && words1[i] == words2[i]) {
            i++;
        }

        // Step 3: Count matching words from the end (suffix)
        while(j < len1 && j < len2 && words1[len1 - 1 - j] == words2[len2 - 1 - j]) {
            j++;
        }

        // Step 4: Return true if the sum of matching prefix and suffix words is 
        //         greater than or equal to the shorter sentence
        return i + j >= min(len1, len2);
    }

private:
    // Helper function to split a sentence into words using space as the delimiter
    vector<string> split(const string& s) {
        vector<string> words;
        istringstream iss(s);  // Create an input string stream from the sentence
        string word;

        // Extract each word and store it in the vector
        while (iss >> word) {
            words.push_back(word);
        }

        return words;
    }
};

int main() {
    // Example test case
    Solution solution;
    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";

    if (solution.areSentencesSimilar(sentence1, sentence2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

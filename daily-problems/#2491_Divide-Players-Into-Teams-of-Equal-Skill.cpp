// #2491 Divide Players Into Teams of Equal Skill
// Date: 2024/10/04 Friday

// Problem Statement
// You are given a vector of integers skill. 
//You have to divide the players into two teams such that the sum of the skills of the players in each team is the same. 
//If it is not possible to divide the players into two teams such that the sum of the skills of the players in each team is the same, return -1. 
//Otherwise, return the maximum possible product of the skills of the players in each team.    

// Concepts Used
// 1. Sorting
// 2. Two Pointer Technique


//Steps:
// 1. Sort the skill vector
// 2. Find the sum of the first and last element
// 3. Iterate through the vector and check if the sum of the current element and the last element is equal to the sum of the first and last element
// 4. If it is not equal return -1
// 5. If it is equal then multiply the current element with the last element and add it to the result
// 6. Decrement the last element
// 7. Return the result

// Time Complexity Analysis
// Sorting the vector takes O(nlogn) time
// Iterating through the vector takes O(n) time
// So the total time complexity is O(nlogn)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Sorting the skill vector so that we can easily find the sum of the first and last 
        sort(skill.begin(), skill.end());
        int right = skill.size() - 1;
        int sum = skill[0] + skill[right];
        long long res=0;
        for(int i = 0; i < static_cast<int>((skill.size()) /2); i++) {
            if(skill[i] + skill[right] != sum) {
                return -1;
            }
            res += (long long)skill[i] * skill[right];
            right--;
        }
        return res;
    }
};

int main() {
    Solution solution;
    // vector<int> skill = {1, 2, 3, 4, 5, 3};
    vector<int> skill = {4,3};
    // vector<int> skill = {1,1,2,3};
    cout << solution.dividePlayers(skill) << endl;
    return 0;
}

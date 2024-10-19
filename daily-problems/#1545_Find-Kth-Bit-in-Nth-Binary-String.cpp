// #Problem 1545: Find K-th Bit in N-th Binary String
// Date: 2024/10/17 Thursday

// Problem Statement:
// Given two positive integers n and k, the binary string Sn is formed as follows:
// S1 = "0"
// Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
// Where + denotes the concatenation operation, reverse(x) returns the reversed string x, 
// and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

// Approach:
// 1. Use recursion to find the kth bit in the binary string Sn.
// 2. We avoid generating the string by calculating its properties directly.
// 3. The length of Sn is (2^n - 1), and we leverage the recursive structure to determine the kth bit.
// 4. Use the middle position (length of Sn / 2) to determine the behavior of the current bit.
// 5. If the bit is in the second half, we refer to the reverse and inverted portion of the string.

// Time Complexity:
// The time complexity is O(n) due to recursive steps, where n is the input.

// Space Complexity:
// The space complexity is O(n) for the recursion stack.

#include <iostream>
using namespace std;

class Solution {
public:
    // Recursive function to find the k-th bit in Sn
    char findKthBit(int n, int k) {
        // Base case: if n is 1, the string is "0", so return '0'
        if (n == 1) {
            return '0';
        }
        
        // Length of the current string Sn is (2^n - 1)
        int length = (1 << n) - 1;
        int mid = length / 2 + 1; // Middle position of the current string

        if (k == mid) {
            // If k is at the middle, it is always '1'
            return '1';
        } else if (k < mid) {
            // If k is in the first half, recursively find in Sn-1
            return findKthBit(n - 1, k);
        } else {
            // If k is in the second half, use the reverse-invert logic
            // Find the corresponding index in the first half
            int mirroredIndex = mid - (k - mid);
            // Recursively find the bit in Sn-1 and invert it
            return findKthBit(n - 1, mirroredIndex) == '0' ? '1' : '0';
        }
    }
};

int main() {
    Solution solution;

    // Example 1
    int n1 = 3, k1 = 1;
    cout << "The " << k1 << "-th bit in S" << n1 << " is: " << solution.findKthBit(n1, k1) << endl; // Output: 0

    // Example 2
    int n2 = 4, k2 = 11;
    cout << "The " << k2 << "-th bit in S" << n2 << " is: " << solution.findKthBit(n2, k2) << endl; // Output: 1

    // Example 3
    int n3 = 2, k3 = 3;
    cout << "The " << k3 << "-th bit in S" << n3 << " is: " << solution.findKthBit(n3, k3) << endl; // Output: 1

    return 0;
}

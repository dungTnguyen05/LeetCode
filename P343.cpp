/*
343. Integer Break
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

Constraints:
2 <= n <= 58
*/

// Insight: as much 2s and 3s as possible.
// Any number >= 4 can be broken down into 2s and 3s, which make the product larger.
// How much 2s and 3s?
// As 2 + 2 + 2 = 3 + 3, and 2 * 2 * 2 < 3 * 3, we should use 3s as much as possible.

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }

        if (n % 3 == 0) {
            return pow(3, n/3);
        }

        if (n % 3 == 1) {
            return 4 * pow(3, (n - 1)/3 - 1); 
        }

        return 2 * pow(3, (n - 2)/3);
    }
};
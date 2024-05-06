/*
1447. Simplified Fractions
Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can return the answer in any order.

Example 3:
Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]

Constraints:
1 <= n <= 100
*/

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (__gcd(i, j) == 1) {
                    res.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }

        return res;
    }
};
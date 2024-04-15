/*
1281. Subtract the Product and Sum of Digits of an Integer
Given an integer number n, return the difference between the product of its digits and the sum of its digits.

Constraints:
1 <= n <= 10^5
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        int prod = 1;
        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            prod *= s[i] - '0';
            sum += s[i] - '0';
        }

        return prod - sum;
    }
};
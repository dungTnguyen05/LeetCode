/*
2544. Alternating Digit Sum
You are given a positive integer n. Each digit of n has a sign according to the following rules:
The most significant digit is assigned a positive sign.
Each other digit has an opposite sign to its adjacent digits.
Return the sum of all digits with their corresponding sign.

Constraints:
1 <= n <= 109
*/

class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0;
        int sign = 1;
        string s = to_string(n);

        for (int i = 0; i < s.size(); i++) {
            res += sign * (s[i] - '0');
            sign = -sign;
        }

        return res;
    }
};
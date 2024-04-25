/*
3099. Harshad Number
An integer divisible by the sum of its digits is said to be a Harshad number. You are given an integer x. Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.

Constraints:
1 <= x <= 100
*/

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum_digits = 0;
        string s = to_string(x);

        for (int i = 0; i < s.size(); i++) {
            sum_digits += s[i] - '0';
        }

        if (x % sum_digits == 0) {
            return sum_digits;
        }

        return -1;
    }
};

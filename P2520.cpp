/*
2520. Count the Digits That Divide a Number
Given an integer num, return the number of digits in num that divide num.
An integer val divides nums if nums % val == 0.

Constraints:
1 <= num <= 109
num does not contain 0 as one of its digits.
*/

class Solution {
public:
    int countDigits(int num) {
        string s = to_string(num);
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            int digit = s[i] - '0';
            
            if (num % digit == 0) {
                count++;
            }
        }

        return count;
    }
};
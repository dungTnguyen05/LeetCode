/*
258. Add Digits
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Constraints:
0 <= num <= 2^31 - 1
*/

class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            sum += s[i] - '0';
        }

        if (sum % 9 == 0 && num != 0) {
            return 9;
        }

        return sum % 9;
    }
};
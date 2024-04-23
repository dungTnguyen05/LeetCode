/*
2864. Maximum Odd Binary Number
You are given a binary string s that contains at least one '1'.
You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
Return a string representing the maximum odd binary number that can be created from the given combination.
Note that the resulting string can have leading zeros.

Constraints:
1 <= s.length <= 100
s consists only of '0' and '1'.
s contains at least one '1'.
*/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                count++;
            }
        }

        return string(count - 1, '1') + string(s.size() - count, '0') + '1';
    }
};
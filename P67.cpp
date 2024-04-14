/*
67. Add Binary
Given two binary strings a and b, return their sum as a binary string.

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int a_index = a.size() - 1;
        int b_index = b.size() - 1;
        int temp = 0;

        while (a_index >= 0 || b_index >= 0 || temp == 1) {
            if (a_index >= 0) {
                temp += a[a_index] - '0'; // ASCII 
                a_index--;
            }

            if (b_index >= 0) {
                temp += b[b_index] - '0'; // ASCII
                b_index--;
            }

            res += temp % 2 + '0';
            temp /= 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
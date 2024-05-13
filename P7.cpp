/*
7. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
-2^31 <= x <= 2^31 - 1
*/

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        string res;

        if (s[0] == '-') {
            res += '-';

            for (int i = s.size() - 1; i >= 1; i--) {
                res += s[i];
            }
        }

        else {
            for (int i = s.size() - 1; i >= 0; i--) {
                res += s[i];
            }
        }

        try {
            return stoi(res);
        } 
        
        catch (out_of_range) {
            return 0;
        }
    }
};
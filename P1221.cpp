/*
1221. Split a String in Balanced Strings
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
Given a balanced string s, split it into some number of substrings such that:
Each substring is balanced.
Return the maximum number of balanced strings you can obtain.

Example 1:
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Constraints:
2 <= s.length <= 1000
s[i] is either 'L' or 'R'.
s is a balanced string.
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                balance++;
            }

            else {
                balance--;
            }

            if (balance == 0) {
                count++;
            }
        }

        return count;
    }
};
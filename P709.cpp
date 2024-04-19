/*
709. To Lower Case
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

Constraints:
1 <= s.length <= 100
s consists of printable ASCII characters.
*/

class Solution {
public:
    string toLowerCase(string s) {
        string res;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 65 && s[i] <= 90) {
                res += s[i] + 32;
            }

            else {
                res += s[i];
            }
        }

        return res;
    }
};
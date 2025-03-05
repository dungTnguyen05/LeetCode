/*
844. Backspace String Compare
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.

Follow up: Can you solve it in O(n) time and O(1) space?
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> s1;
        vector<char> t1;

        for (char& c: s) {
            if (c == '#') {
                if (!s1.empty()) {
                    s1.pop_back();
                }
            }

            else {
                s1.push_back(c);
            }
        }

        for (char& c: t) {
            if (c == '#') {
                if (!t1.empty()) {
                    t1.pop_back();
                }
            }

            else {
                t1.push_back(c);
            }
        }

        if (s1.size() != t1.size()) {
            return false;
        }

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != t1[i]) {
                return false;
            }
        }

        return true;
    }
};
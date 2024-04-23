/*
2810. Faulty Keyboard
Your laptop keyboard is faulty, and whenever you type a character 'i' on it, it reverses the string that you have written. Typing other characters works as expected.
You are given a 0-indexed string s, and you type each character of s using your faulty keyboard.
Return the final string that will be present on your laptop screen.

Example 1:
Input: s = "string"
Output: "rtsng"

Constraints:
1 <= s.length <= 100
s consists of lowercase English letters.
s[0] != 'i'
*/

class Solution {
public:
    string finalString(string s) {
        string res;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'i') {
                res += s[i];
            }

            else {
                reverse(res.begin(), res.end());
            }
        }

        return res;
    }
};
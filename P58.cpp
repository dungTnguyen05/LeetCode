/*
58. Length of Last Word
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Constraints:
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int begin = -1;
        int end = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != 32) {
                end = i;
                break;
            }
        }

        for (int i = end - 1; i >= 0; i--) {
            if (s[i] == 32) {
                begin = i;
                break;
            }
        }

        return end - begin;
    }
};
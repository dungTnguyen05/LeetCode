/*
1876. Substrings of Size Three with Distinct Characters
A string is good if there are no repeated characters.
Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
A substring is a contiguous sequence of characters in a string.

Constraints:
1 <= s.length <= 100
s​​​​​​ consists of lowercase English letters.
*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int res = 0;

        if (s.size() < 3) {
            return res;
        }

        for (int i = 0; i < s.size() - 2; i++) {
            if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
                res++;
            }
        }

        return res;
    }
};
/*
2351. First Letter to Appear Twice
Given a string s consisting of lowercase English letters, return the first letter to appear twice.
Note:
A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
s will contain at least one letter that appears twice.

Example 1:
Input: s = "abccbaacz"
Output: "c"

Constraints:
2 <= s.length <= 100
s consists of lowercase English letters.
s has at least one repeated letter.
*/

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> mp;

        for (char c: s) {
            mp[c]++;

            if (mp[c] == 2) {
                return c;
            }
        }

        return 'a';
    }
};
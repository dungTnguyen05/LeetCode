/*
1941. Check if All Characters Have Equal Number of Occurrences
Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;

        for (char c: s) {
            mp[c]++;
        }

        int count = mp[s[0]];

        for (auto it: mp) {
            if (it.second != count) {
                return false;
            }
        }

        return true;
    }
};
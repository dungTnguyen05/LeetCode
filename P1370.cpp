/*
1370. Increasing Decreasing String
You are given a string s. Reorder the string using the following algorithm:

1. Pick the smallest character from s and append it to the result.
2. Pick the smallest character from s which is greater than the last appended character to the result and append it.
3. Repeat step 2 until you cannot pick more characters.
4. Pick the largest character from s and append it to the result.
5. Pick the largest character from s which is smaller than the last appended character to the result and append it.
6. Repeat step 5 until you cannot pick more characters.
7. Repeat the steps from 1 to 6 until you pick all characters from s.

In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.

Example 1:
Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"

Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters.
*/

class Solution {
public:
    string sortString(string s) {
        string res;
        unordered_map<char, int> mp;

        for (char c: s) {
            mp[c]++;
        }

        while (res.size() != s.size()) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (mp[c] > 0) {
                    res += c;
                    mp[c]--;
                }
            }

            for (char c = 'z'; c >= 'a'; c--) {
                if (mp[c] > 0) {
                    res += c;
                    mp[c]--;
                }
            }
        }

        return res;
    }
};
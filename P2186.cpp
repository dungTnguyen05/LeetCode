/*
2186. Minimum Number of Steps to Make Two Strings Anagram II
You are given two strings s and t. In one step, you can append any character to either s or t.
Return the minimum number of steps to make s and t anagrams of each other.
An anagram of a string is a string that contains the same characters with a different (or the same) ordering.

Example 1:
Input: s = "leetcode", t = "coats"
Output: 7

Constraints:
1 <= s.length, t.length <= 2 * 10^5
s and t consist of lowercase English letters.
*/

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        int res = 0;

        for (char c: s) {
            mp[c]++;
        }

        for (char c: t) {
            mp[c]--;
        }

        for (auto it: mp) {
            res += abs(it.second);
        }

        return res;
    }
};

// faster with using vector instead of map
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26, 0);
        int res = 0;

        for (char c: s) {
            v[c - 'a']++;
        }

        for (char c: t) {
            v[c - 'a']--;
        }

        for (int num: v) {
            res += abs(num);
        }

        return res;
    }
};
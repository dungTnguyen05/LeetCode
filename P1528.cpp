/*
1528. Shuffle String
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
Return the shuffled string.

Example 1:
https://assets.leetcode.com/uploads/2020/07/09/q1.jpg
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.

Constraints:
s.length == indices.length == n
1 <= n <= 100
s consists of only lowercase English letters.
0 <= indices[i] < n
All values of indices are unique.
*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int, char> mp;
        string res;

        for (int i = 0; i < s.size(); i++) {
            mp[indices[i]] = s[i]; 
        }

        for (auto it: mp) {
            res += it.second;
        }

        return res;
    }
};
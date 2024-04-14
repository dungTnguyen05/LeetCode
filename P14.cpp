/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string max_prefix;
        string min_str;
        int min_size = 200;

        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < min_size) {
                min_str = strs[i];
                min_size = strs[i].size();
            }
        }

        for (int i = 0; i < min_size; i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (min_str[i] != strs[j][i]) {
                    return max_prefix;
                }
            }

            max_prefix += min_str[i];
        }

        return max_prefix;
    }
};
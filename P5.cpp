/*
5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

// TC: O(n^2)
class Solution {
public:
    string longestPalindrome(string& s) {
        int max_length = 1;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            int temp1 = expandAroundCenter(s, i, i);
            int temp2 = expandAroundCenter(s, i, i + 1);
            int temp = max(temp1, temp2);

            if (temp > max_length) {
                start = i - (temp - 1)/2;
                max_length = temp; 
            }
        }

        return s.substr(start, max_length);
    }

    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }
};
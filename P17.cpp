/*
17. Letter Combination of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

// method: backtracking
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> res;
        string currentCombination = "";
        backtrack(digits, 0, currentCombination, res, mp);

        return res;
    }

    void backtrack(string& digits, int idx, string& currentCombination, vector<string>& res, unordered_map<char, string>& mp) {
        if (idx == digits.size()) {
            res.push_back(currentCombination);
            return;
        }

        char digit = digits[idx];
        string letters = mp[digit];

        for (char& letter: letters) {
            currentCombination.push_back(letter);
            backtrack(digits, idx + 1, currentCombination, res, mp);
            currentCombination.pop_back();
        }
    }
};
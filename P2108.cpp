/*
2108. Find First Palindrome String in the Array
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.

Example 1:
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists only of lowercase English letters.
*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string& word: words) {
            bool isPalindrome = true;

            for (int i = 0; i < word.size()/2; i++) {
                if (word[i] != word[word.size() - 1 - i]) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome == true) {
                return word;
            }
        }


        return "";
    }
};
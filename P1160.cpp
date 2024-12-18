/*
1160. Find Words That Can Be Formed by Characters
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.

Example 1:
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

Constraints:
1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
words[i] and chars consist of lowercase English letters.
*/

// using vector instead of hash map would be slightly faster
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> char_count;

        for (char& c: chars) {
            char_count[c]++;
        }

        int res = 0;

        for (string& word: words) {
            unordered_map<char, int> word_count;

            for (char& c: word) {
                word_count[c]++;
            }

            bool is_good = true;

            for (auto& it: word_count) {
                if (it.second > char_count[it.first]) {
                    is_good = false;
                    break;
                }
            }

            if (is_good) {
                res += word.size();
            }
        }

        return res;
    }
};
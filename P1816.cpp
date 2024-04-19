/*
1816. Truncate Sentence
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of only uppercase and lowercase English letters (no punctuation).
For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
You are given a sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains only the first k​​​​​​ words. Return s​​​​​​ after truncating it.

Constraints:
1 <= s.length <= 500
k is in the range [1, the number of words in s].
s consist of only lowercase and uppercase English letters and spaces.
The words in s are separated by a single space.
There are no leading or trailing spaces.
*/

class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        int space_count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 32) {
                space_count++;

                if (space_count == k) {
                    break;
                }
            }

            res += s[i];
        }

        return res;
    }
};
/*
1832. Check if the Sentence Is Pangram
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

Constraints:
1 <= sentence.length <= 1000
sentence consists of lowercase English letters.
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int freq[26] = {0};
        int sum = 0;

        for (int i = 0; i < sentence.size(); i++) {
            if (freq[sentence[i] - 97] == 0) {
                freq[sentence[i] - 97]++;
                sum++;
            }

            if (sum == 26) {
                return true;
            }
        }

        return false;
    }
};
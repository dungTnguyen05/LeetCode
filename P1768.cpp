/*
1768. Merge Strings Alternately
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Constraints:
1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;

        for (int i = 0; i < min(word1.size(), word2.size()); i++) {
            merged += word1[i];
            merged += word2[i];
        }

        if (word1.size() < word2.size()) {
            for (int i = word1.size(); i < word2.size(); i++) {
                merged += word2[i];
            }
        }

        else if (word1.size() > word2.size()) {
            for (int i = word2.size(); i < word1.size(); i++) {
                merged += word1[i];
            }
        }

        return merged;
    }
};
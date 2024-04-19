/*
2114. Maximum Number of Words Found in Sentences
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
You are given an array of strings sentences, where each sentences[i] represents a single sentence.
Return the maximum number of words that appear in a single sentence.

Constraints:
1 <= sentences.length <= 100
1 <= sentences[i].length <= 100
sentences[i] consists only of lowercase English letters and ' ' only.
sentences[i] does not have leading or trailing spaces.
All the words in sentences[i] are separated by a single space.
*/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        vector<int> space_count;
        int temp = 0;
        int res = 0;

        for (int i = 0; i < sentences.size(); i++) {
            for (int j = 0; j < sentences[i].size(); j++) {
                if (sentences[i][j] == 32) {
                    temp++;
                }
            }

            space_count.push_back(temp);

            if (temp > res) {
                res = temp;
            }

            temp = 0;
        }

        return res + 1;
    }
};


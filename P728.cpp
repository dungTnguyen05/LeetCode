/*
728. Self Dividing Numbers
A self-dividing number is a number that is divisible by every digit it contains.
For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to contain the digit zero.
Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].

Constraints:
1 <= left <= right <= 104
*/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;

        for (int i = left; i <= right; i++) {
            string s = to_string(i);

            for (int j = 0; j < s.size(); j++) {
                int digit = s[j] - '0';

                if (digit == 0 || i % digit != 0) {
                    break;
                }

                if (j == s.size() - 1) {
                    if (i % digit == 0) {
                        res.push_back(i);
                    }
                }
            }
        }

        return res;
    }
};
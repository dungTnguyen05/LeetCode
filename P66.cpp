/*
66. Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int count = 0;

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                count++;
            }

            else {
                break;
            }
        }

        if (count == digits.size()) {
            res.push_back(1);

            for (int i = 0; i < digits.size(); i++) {
                res.push_back(0);
            }

            return res;
        }
        
        for (int i = 0; i < digits.size() - count - 1; i++) {
            res.push_back(digits[i]);
        }

        res.push_back(digits[digits.size() - count - 1] + 1);

        for (int i = 0; i < count; i++) {
            res.push_back(0);
        }

        return res;
    }
};
/*
2160. Minimum Sum of Four Digit Number After Splitting Digits
You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.
For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
Return the minimum possible sum of new1 and new2.

Constraints:
1000 <= num <= 9999
*/

class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        vector<int> digit;

        for (int i = 0; i < s.size(); i++) {
            digit.push_back(s[i] - '0');
        }

        sort(digit.begin(), digit.end());

        return 10 * digit[0] + digit[3] + 10 * digit[1] + digit[2];
    }
};
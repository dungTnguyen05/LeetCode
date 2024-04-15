/*
1323. Maximum 69 Number
You are given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Constraints:
1 <= num <= 10^4
num consists of only 6 and 9 digits.
*/

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }

        int res = stoi(s);
        
        return res;
    }
};
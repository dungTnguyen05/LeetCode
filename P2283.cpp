/*
2283. Check if Number Has Equal Digit Count and Digit Value
You are given a 0-indexed string num of length n consisting of digits.
Return true if for every index i in the range 0 <= i < n, the digit i occurs num[i] times in num, otherwise return false.

Example 1:
Input: num = "1210"
Output: true
Explanation:
num[0] = '1'. The digit 0 occurs once in num.
num[1] = '2'. The digit 1 occurs twice in num.
num[2] = '1'. The digit 2 occurs once in num.
num[3] = '0'. The digit 3 occurs zero times in num.
The condition holds true for every index in "1210", so return true.

Constraints:
n == num.length
1 <= n <= 10
num consists of digits.
*/

class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> mp;

        for (char digit: num) {
            mp[digit - '0']++;
        }

        for (int i = 0; i < num.size(); i++) {
            if (mp[i] != num[i] - '0') {
                return false;
            }
        }

        return true;
    }
};
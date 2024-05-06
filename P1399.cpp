/*
1399. Count Largest Group
You are given an integer n.
Each number from 1 to n is grouped according to the sum of its digits.
Return the number of groups that have the largest size.

Example 1:
Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.

Constraints:
1 <= n <= 10^4
*/

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int max_size = 0;
        int res = 0;

        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            int digit_sum = 0;

            for (int j = 0; j < s.size(); j++) {
                digit_sum += s[j] - '0';
            }

            mp[digit_sum]++;

            if (mp[digit_sum] > max_size) {
                max_size = mp[digit_sum];
            }
        }

        for (auto it: mp) {
            if (it.second == max_size) {
                res++;
            }
        }

        return res;
    }
};
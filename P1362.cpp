/*
1362. Closest Divisors
Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
Return the two integers in any order.

Example 1:
Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.

Constraints:
1 <= num <= 10^9
*/

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> res;
        int abs_diff;

        for (int i = sqrt(num + 1); i >= 1; i--) {
            if ((num + 1) % i == 0) {
                res = {i, (num + 1)/i};
                abs_diff = (num + 1)/i - i;
                break;
            }
        }

        for (int i = sqrt(num + 2); i >= 1; i--) {
            if ((num + 2) % i == 0) {
                if ((num + 2)/i - i < abs_diff) {
                    res = {i, (num + 2)/i};
                }

                break;
            }
        }

        return res;
    }
};
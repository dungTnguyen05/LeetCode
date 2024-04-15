/*
1742. Maximum Number of Balls in a Box
You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), and an infinite number of boxes numbered from 1 to infinity.
Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. For example, the ball number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball number 10 will be put in the box number 1 + 0 = 1.
Given two integers lowLimit and highLimit, return the number of balls in the box with the most balls.

Constraints:
1 <= lowLimit <= highLimit <= 105
*/

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int box[46] = {0};
        int res = 0;

        for (int i = lowLimit; i <= highLimit; i++) {
            string s = to_string(i);
            int sum_digit = 0;

            for (int j = 0; j < s.size(); j++) {
                sum_digit += s[j] - '0';
            }

            box[sum_digit]++;

            if (box[sum_digit] > res) {
                res = box[sum_digit];
            }
        }

        return res;
    }
};
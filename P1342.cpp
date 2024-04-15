/*
1342. Number of Steps to Reduce a Number to Zero
Given an integer num, return the number of steps to reduce it to zero.
In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

Constraints:
0 <= num <= 106
*/

// Insight: base 10 to base 2, e.g. 14 = 1110(2) => each number 1: + 2 steps, each number 0: + 1 step
// Other way: recursion

class Solution {
public:
    int numberOfSteps(int num) {
        int step = 0;

        while (num != 0) {
            if (num % 2 == 0 || num == 1) {
                step += 1;
            }

            else {
                step += 2;
            }

            num = num/2;
        }

        return step;
    }
};
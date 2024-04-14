/*
69. Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.

Constraints:
0 <= x <= 2^31 - 1
*/

class Solution {
public:
    int mySqrt(int x) {
        int a = 0;
        int b = x;

        while (a <= b) {
            long long temp = (a + b)/2;

            if (temp * temp == x) {
                return temp;
            }

            else if (temp * temp < x) {
                a = temp + 1;
            }

            else {
                b = temp - 1;
            }
        }

        return b;
    }
};
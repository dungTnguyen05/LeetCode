/*
50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

Constraints:
-100.0 < x < 100.0
-2^31 <= n <= 2^31 - 1
n is an integer.
Either x is not zero or n > 0.
-10^4 <= x^n <= 10^4
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        if (n > 0) {
            if (n % 2 == 0) {
                return myPow(x * x, n/2);
            }

            return x * myPow(x * x, (n - 1)/2);
        }

        if (n < 0) {
            if (n % 2 == 0) {
                return myPow(x * x, n/2);
            }

            return myPow(x * x, (n + 1)/2)/x;
        }

        return 0;
    }
};
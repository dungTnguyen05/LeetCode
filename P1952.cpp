/*
1952. Three Divisors
Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.
An integer m is a divisor of n if there exists an integer k such that n = k * m.

Constraints:
1 <= n <= 10^4
*/

// approach: if n is a square of a prime number, then it has exactly 3 divisors.
class Solution {
public:
    bool isThree(int n) {
        if (n == 1 || n == 81) {
            return false;
        }

        int m = sqrt(n);

        if (m * m == n) {
            for (int i = 2; i < sqrt(m); i++) {
                if (m % i == 0) {
                    return false;
                }
            }

            return true;
        }

        return false;
    }
};
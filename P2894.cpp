/*
2894. Divisible and Non-divisible Sums Difference

You are given positive integers n and m.
Define two integers, num1 and num2, as follows:
num1: The sum of all integers in the range [1, n] that are not divisible by m.
num2: The sum of all integers in the range [1, n] that are divisible by m.
Return the integer num1 - num2.

Constraints:
1 <= n, m <= 1000
*/

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1, num2 = 0;
        int sum = n * (n + 1);
        sum /= 2;

        for (int i = m; i <= n; i += m) {
            num2 += i;
        }

        num1 = sum - num2;

        return num1 - num2;
    }
};
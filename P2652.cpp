/*
2652. Sum Multiples
Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.
Return an integer denoting the sum of all numbers in the given range satisfying the constraint.

Constraints:
1 <= n <= 103
*/

class Solution {
public:
    int sumOfMultiples(int n) {
        int sum_3 = ((n - n % 3) + 3) * ((((n - n % 3) - 3)/3) + 1)/2;
        int sum_5 = ((n - n % 5) + 5) * ((((n - n % 5) - 5)/5) + 1)/2;
        int sum_7 = ((n - n % 7) + 7) * ((((n - n % 7) - 7)/7) + 1)/2;
        int sum_15 = ((n - n % 15) + 15) * ((((n - n % 15) - 15)/15) + 1)/2;
        int sum_21 = ((n - n % 21) + 21) * ((((n - n % 21) - 21)/21) + 1)/2;
        int sum_35 = ((n - n % 35) + 35) * ((((n - n % 35) - 35)/35) + 1)/2;
        int sum_105 = ((n - n % 105) + 105) * ((((n - n % 105) - 105)/105) + 1)/2;

        int sum = sum_3 + sum_5 + sum_7 - sum_15 - sum_21 - sum_35 + sum_105;

        return sum;
    }
};
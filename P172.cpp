/*
172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.
Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0

Constraints:
0 <= n <= 10^4

Follow up: Could you write a solution that works in logarithmic time complexity?
*/

// time complexity: O(log5(n))
// insight: the number of trailing zeroes is determined by the number of 5s in the prime factorization of n!
// because the number of 2s is always greater than the number of 5s, we only need to count the number of 5s
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;

        for (int i = 5; i <= n; i *= 5) {
            count += n/i;
        }

        return count;
    }
};

/*
another solution:
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;

        for (int i = 5; i <= n; i += 5) {
            int j = i;

            while (j % 5 == 0) {
                j /= 5;
                count++;
            }
        }
};
*/
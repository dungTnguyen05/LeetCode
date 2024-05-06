/*
1492. The kth Factor of n
You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.
Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

Constraints:
1 <= k <= n <= 1000

Follow up:
Could you solve this problem in less than O(n) complexity?
*/

// time complexity: O(sqrt(n));
class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;

        for (int i = 1; i < sqrt(n); i++) {
            if (n % i == 0) {
                count++;
            }

            if (count == k) {
                return i;
            }
        }

        for (int i = sqrt(n); i >= 1; i--) {
            if (n % i == 0) {
                count++;
            }

            if (count == k) {
                return n/i;
            }
        }

        return -1;
    }
};
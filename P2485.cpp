/*
2485. Find the Pivot Integer
Given a positive integer n, find the pivot integer x such that:
The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

Constraints:
1 <= n <= 1000
*/

// 1 + ... + x = x + .... + n
// x * (x + 1)/2 = (1/2) * (1 + ... + n + x)
// x * (x + 1) = n * (n + 1)/2 + x
// x^2 = n * (n + 1)/2
// x = sqrt(n * (n + 1)/2)

class Solution {
public:
    int pivotInteger(int n) {
        int x = sqrt(n * (n + 1)/2);

        if (x * x == n * (n + 1)/2) {
            return x;
        }

        return -1;
    }
};
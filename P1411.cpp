/*
1411. Number of Ways to Paint N x 3 Grid
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

Example 1:
https://assets.leetcode.com/uploads/2020/03/26/e1.png
Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown.

Example 2:
Input: n = 5000
Output: 30228214

Constraints:
n == grid.length
1 <= n <= 5000
*/

/*
Mathematical approach: result = f(n) = a(n) + b(n), where:
a(n): the number of possible (n x 3) grids such that in the last row, the 1st and 3rd cell have the same color
b(n): the number of possible (n x 3) grids such that in the last row, the 1st and 3rd cell have different colors

We can deduce the formulas:
a(n + 1) = 3a(n) + 2b(n)
b(n + 1) = 2a(n) + 2b(n) 
*/
class Solution {
public:
    int numOfWays(int n) {
        vector<long long> a(n + 1);
        vector<long long> b(n + 1);
        a[1] = 6;
        b[1] = 6;
        int mod = 1e9 + 7;

        for (int i = 2; i <= n; i++) {
            a[i] = (3 * a[i - 1] + 2 * b[i - 1]) % mod;
            b[i] = (2 * a[i - 1] + 2 * b[i - 1]) % mod;
        }

        return (a[n] + b[n]) % mod;
    }
};
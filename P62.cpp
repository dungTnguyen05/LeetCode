/*
62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

Example 1:
https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png
Input: m = 3, n = 7
Output: 28

Constraints:
1 <= m, n <= 100
*/

// insight: to reach the last grid, we need to RIGHT (m - 1) times and DOWN (n - 1) times. 
// That is, we need to choose (m - 1) times from (m + n - 2) times. 
// So, the answer is C(m + n - 2, m - 1) = (m + n - 2)!/((m - 1)! * (n - 1)!).

class Solution {
public:
    int uniquePaths(int m, int n) {
        long double res = 1;

        for (int i = 1; i <= n - 1; i++) {
            res *= i + m - 1;
            res /= i;
        }

        return res;
    }
};
/*
2428. Maximum Sum of an Hourglass
You are given an m x n integer matrix grid.
We define an hourglass as a part of the matrix with the following form:
https://assets.leetcode.com/uploads/2022/08/21/img.jpg
Return the maximum sum of the elements of an hourglass.
Note that an hourglass cannot be rotated and must be entirely contained within the matrix.

Constraints:
m == grid.length
n == grid[i].length
3 <= m, n <= 150
0 <= grid[i][j] <= 106
*/

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size() - 2; i++) {
            for (int j = 0; j < grid[i].size() - 2; j++) {
                int temp = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                res = max(res, temp);
            }
        }

        return res;
    }
};
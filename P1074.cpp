/*
1074. Number of Submatrices That Sum to Target
Given a matrix and a target, return the number of non-empty submatrices that sum to target.
A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

Example 1:
https://assets.leetcode.com/uploads/2020/09/02/mate1.jpg
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.

Example 2:
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

Example 3:
Input: matrix = [[904]], target = 0
Output: 0

Constraints:
1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i][j] <= 1000
-10^8 <= target <= 10^8
*/

// time complexity: O(m * n^2)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        for (int start_col = 0; start_col < cols; start_col++) {
            for (int end_col = start_col; end_col < cols; end_col++) {
                unordered_map<int, int> sum_count;
                sum_count[0] = 1; // base case: empty matrix
                int curr = 0;

                for (int row = 0; row < rows; row++) {
                    curr += matrix[row][end_col];

                    if (start_col > 0) {
                        curr -= matrix[row][start_col - 1];
                    }

                    count += sum_count[curr - target];
                    sum_count[curr]++;
                }
            }
        }

        return count;
    }
};
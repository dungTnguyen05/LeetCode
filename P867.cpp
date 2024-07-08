/*
867. Transpose Matrix
Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 10^5
-10^9 <= matrix[i][j] <= 10^9
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transpose(matrix[0].size(), vector<int>(matrix.size()));

        for (int i = 0; i < transpose.size(); i++) {
            for (int j = 0; j < transpose[i].size(); j++) {
                transpose[i][j] = matrix[j][i];
            }
        }

        return transpose;
    }
};
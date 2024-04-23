/*
1572. Matrix Diagonal Sum
Given a square matrix mat, return the sum of the matrix diagonals.
Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

Constraints:
n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum_diagonal = 0;

        for (int i = 0; i < mat.size(); i++) {
            sum_diagonal += mat[i][i];
            sum_diagonal += mat[i][mat.size() - 1 - i];
        }

        if (mat.size() % 2 == 1) {
            sum_diagonal -= mat[mat.size()/2][mat.size()/2];
        }

        return sum_diagonal;
    }
};
/*
2482. Difference Between Ones and Zeros in Row and Column
You are given a 0-indexed m x n binary matrix grid.
A 0-indexed m x n difference matrix diff is created with the following procedure:
Let the number of ones in the ith row be onesRowi.
Let the number of ones in the jth column be onesColj.
Let the number of zeros in the ith row be zerosRowi.
Let the number of zeros in the jth column be zerosColj.
diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj.
Return the difference matrix diff.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
grid[i][j] is either 0 or 1.
*/

// number of 1s in a row = sum of this row
// number of 1s in a col = sum of this col
// number of 0s in a row = grid.size() - sum of this row
// number of 0s in a col = grid[i].size() - sum of this col

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> row_sum, col_sum;
        int temp_sum = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                temp_sum += grid[i][j];
            }

            row_sum.push_back(temp_sum);
            temp_sum = 0;
        }

        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                temp_sum += grid[j][i];
            }

            col_sum.push_back(temp_sum);
            temp_sum = 0;
        }

        vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size()));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                diff[i][j] = 2 * row_sum[i] + 2 * col_sum[j] - grid.size() - grid[i].size();
            }
        }

        return diff;
    }
};
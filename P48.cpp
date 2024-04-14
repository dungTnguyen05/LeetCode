/*
48. Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg
https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int num_row = matrix.size();
        int num_col = matrix.size();

        // transpose
        for (int i = 0; i < num_row - 1; i++) {
            for (int j = i + 1; j < num_col; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // flip
        for (int i = 0; i < num_row; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        cout << "[";

        for (int i = 0; i < num_row; i++) {
            cout << "[";

            for (int j = 0; j < num_col; j++) {
                if (j != num_col - 1) {
                    cout << matrix[i][j] << ",";
                }

                else {
                    cout << matrix[i][j];
                }
            }

            if (i != num_row - 1) {
                cout << "],";
            }

            else {
                cout << "]";
            }
        }
        
        cout << "]";
    }
};
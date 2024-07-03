/*
1314. Matrix Block Sum
Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 
Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n, k <= 100
1 <= mat[i][j] <= 100
*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefixSum(m+1, vector<int>(n+1, 0));
        
        // Compute prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = mat[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
            }
        }
        
        // Calculate submatrix sums
        vector<vector<int>> answer(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Calculate boundaries of the submatrix
                int r1 = max(0, i-k), c1 = max(0, j-k);
                int r2 = min(m-1, i+k), c2 = min(n-1, j+k);

                // Convert boundaries for prefixSum usage
                r1++; c1++; r2++; c2++;
                
                // Calculate sum using prefixSum
                answer[i][j] = prefixSum[r2][c2] - prefixSum[r2][c1-1] - prefixSum[r1-1][c2] + prefixSum[r1-1][c1-1];
            }
        }
        
        return answer;
    }
};
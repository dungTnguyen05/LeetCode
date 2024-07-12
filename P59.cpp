/*
59. Spiral Matrix II
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:
1 <= n <= 20
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n, vector<int>(n));
        int num = 1;
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                spiral[top][i] = num++;
            }

            top++;

            for (int i = top; i <= bottom; i++) {
                spiral[i][right] = num++;
            }

            right--;

            for (int i = right; i >= left; i--) {
                spiral[bottom][i] = num++;
            }

            bottom--;

            for (int i = bottom; i >= top; i--) {
                spiral[i][left] = num++;
            }

            left++;
        }

        return spiral;
    }
};
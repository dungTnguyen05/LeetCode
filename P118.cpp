/*
118. Pascal's Triangle 
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0].push_back(1);

        for (int i = 1; i < numRows; i++) {
            res[i].push_back(1);

            for (int j = 0; j < res[i - 1].size() - 1; j++) {
                res[i].push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }

            res[i].push_back(1);
        }

        return res;
    }
};
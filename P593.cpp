/*
593. Valid Square
Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
A valid square has four equal sides with positive length and four equal angles (90-degree angles).

Example 1:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true

Constraints:
p1.length == p2.length == p3.length == p4.length == 2
-10^4 <= xi, yi <= 10^4
*/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        vector<int> d_squared;

        if (p[0] == p[1] && p[1] == p[2] && p[2] == p[3]) {
            return false;
        }

        for (int i = 0; i < p.size() - 1; i++) {
            for (int j = i + 1; j < p.size(); j++) {
                d_squared.push_back(pow(p[i][0] - p[j][0], 2) + pow(p[i][1] - p[j][1], 2));
            }
        }

        sort(d_squared.begin(), d_squared.end());

        if (d_squared[0] == d_squared[3] && d_squared[4] == d_squared[5] && d_squared[4] == 2 * d_squared[3]) {
            return true;
        }

        return false;
    }
};
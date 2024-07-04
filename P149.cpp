/*
149. Max Points on a Line
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:
https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4

Constraints:
1 <= points.length <= 300
points[i].length == 2
-10^4 <= xi, yi <= 10^4
All the points are unique.
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1) {
            return 1;
        }

        map<pair<double, double>, set<int>> lines;
        int res = 0;

        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                double slope;
                double intercept;

                if (points[i][0] == points[j][0]) {
                    slope = INT_MAX;
                    intercept = points[i][0];
                }

                else {
                    slope = (double)(points[i][1] - points[j][1])/(points[i][0] - points[j][0]);
                    intercept = points[i][1] - slope * points[i][0];
                }

                lines[{slope, intercept}].insert(i);
                lines[{slope, intercept}].insert(j);

                if (lines[{slope, intercept}].size() > res) {
                    res = lines[{slope, intercept}].size();
                }
            }
        }

        return res;
    }
};
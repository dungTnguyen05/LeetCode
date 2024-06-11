/*
1637. Widest Vertical Area Between Two Points Containing No Points
Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
Note that points on the edge of a vertical area are not considered included in the area.

Example 1:
https://assets.leetcode.com/uploads/2020/09/19/points3.png
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.

Constraints:
n == points.length
2 <= n <= 105
points[i].length == 2
0 <= xi, yi <= 109
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int res = 0;
        sort(points.begin(), points.end()); // sort according to the first element

        for (int i = 0; i < points.size() - 1; i++) {
            res = max(res, points[i + 1][0] - points[i][0]);
        }

        return res;
    }
};

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> pts;
        int res = 0;

        for (auto it: points) {
            pts.insert(it[0]);
        }

        auto it = pts.begin();
        auto prev = it++; // prev = it before ++, and it++

        for (; it != pts.end(); it++, prev++) {
            res = max(res, *it - *prev);
        }

        return res;
    }
};
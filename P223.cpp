/*
223. Rectangle Area
Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

https://assets.leetcode.com/uploads/2021/05/08/rectangle-plane.png

Constraints:
-104 <= ax1 <= ax2 <= 104
-104 <= ay1 <= ay2 <= 104
-104 <= bx1 <= bx2 <= 104
-104 <= by1 <= by2 <= 104
*/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // s_total = s1 + s2 - s_overlapped
        int s1 = (ax2 - ax1) * (ay2 - ay1);
        int s2 = (bx2 - bx1) * (by2 - by1); 
        int s_overlapped;
        int s_total;

        int cx1 = max(ax1, bx1);
        int cy1 = max(ay1, by1);
        
        int cx2 = min(ax2, bx2);
        int cy2 = min(ay2, by2);

        if (cx1 < cx2 && cy1 < cy2) {
            s_overlapped = (cx2 - cx1) * (cy2 - cy1);
        }

        else {
            s_overlapped = 0;
        }

        s_total = s1 + s2 - s_overlapped;
        
        return s_total;
    }
};
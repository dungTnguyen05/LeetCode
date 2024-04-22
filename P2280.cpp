/*
2280. Minimum Lines to Represent a Line Chart
You are given a 2D integer array stockPrices where stockPrices[i] = [dayi, pricei] indicates the price of the stock on day dayi is pricei. A line chart is created from the array by plotting the points on an XY plane with the X-axis representing the day and the Y-axis representing the price and connecting adjacent points. One such example is shown below:
https://assets.leetcode.com/uploads/2022/03/30/1920px-pushkin_population_historysvg.png
Return the minimum number of lines needed to represent the line chart.

Example 1:
https://assets.leetcode.com/uploads/2022/03/30/ex0.png
Input: stockPrices = [[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
Output: 3

Constraints:
1 <= stockPrices.length <= 10^5
stockPrices[i].length == 2
1 <= dayi, pricei <= 10^9
All dayi are distinct.
*/

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() == 1) {
            return 0;
        }

        sort(stockPrices.begin(), stockPrices.end());
        int lines = 1;

        for (int i = 0; i < stockPrices.size() - 2; i++) {
            long long x1 = stockPrices[i][0], y1 = stockPrices[i][1];
            long long x2 = stockPrices[i + 1][0], y2 = stockPrices[i + 1][1];
            long long x3 = stockPrices[i + 2][0], y3 = stockPrices[i + 2][1];

            if ((x1 - x2) * (y2 - y3) != (x2 - x3) * (y1 - y2)) {
                lines++;
            }
        }

        return lines;

    }
};
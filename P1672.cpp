/*
1672. Richest Customer Wealth
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.
A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

Constraints:
m == accounts.length
n == accounts[i].length
1 <= m, n <= 50
1 <= accounts[i][j] <= 100
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int temp = 0;
        int res = 0;

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 0; j < accounts[i].size(); j++) {
                temp += accounts[i][j];
            }

            if (temp > res) {
                res = temp;
            }

            temp = 0;
        }

        return res;
    }
};
/*
2363. Merge Similar Items
You are given two 2D integer arrays, items1 and items2, representing two sets of items. Each array items has the following properties:
items[i] = [valuei, weighti] where valuei represents the value and weighti represents the weight of the ith item.
The value of each item in items is unique.

Return a 2D integer array ret where ret[i] = [valuei, weighti], with weighti being the sum of weights of all items with value valuei.
Note: ret should be returned in ascending order by value.

Example 1:
Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
Output: [[1,6],[3,9],[4,5]]

Constraints:
1 <= items1.length, items2.length <= 1000
items1[i].length == items2[i].length == 2
1 <= valuei, weighti <= 1000
Each valuei in items1 is unique.
Each valuei in items2 is unique.
*/

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> res;
        map<int, int> mp;

        for (auto item: items1) {
            mp[item[0]] += item[1];
        }

        for (auto item: items2) {
            mp[item[0]] += item[1];
        }

        for (auto it: mp) {
            res.push_back({it.first, it.second});
        }
        
        return res;
    }
};
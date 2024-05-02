/*
1394. Find Lucky Integer in an Array
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
Return the largest lucky integer in the array. If there is no lucky integer return -1.

Constraints:
1 <= arr.length <= 500
1 <= arr[i] <= 500
*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        int res = -1;

        for (int num: arr) {
            mp[num]++;
        }

        for (auto it: mp) {
            if (it.first == it.second) {
                res = max(res, it.first);
            }
        }

        return res;
    }
};
/*
1748. Sum of Unique Elements
You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
Return the sum of all the unique elements of nums.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;

        for (int num: nums) {
            mp[num]++;
        }

        for (auto it: mp) {
            if (it.second == 1) {
                res += it.first;
            }
        }

        return res;
    }
};
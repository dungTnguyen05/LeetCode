/*
2206. Divide Array Into Equal Pairs
You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:
Each element belongs to exactly one pair.
The elements present in a pair are equal.

Return true if nums can be divided into n pairs, otherwise return false.

Example 1:
Input: nums = [3,2,3,2,2,2]
Output: true

Constraints:
nums.length == 2 * n
1 <= n <= 500
1 <= nums[i] <= 500
*/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int num: nums) {
            mp[num]++;
        }

        for (auto it: mp) {
            if (it.second % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};
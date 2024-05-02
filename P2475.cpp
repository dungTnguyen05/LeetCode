/*
2475. Number of Unequal Triplets in Array
You are given a 0-indexed array of positive integers nums. Find the number of triplets (i, j, k) that meet the following conditions:
0 <= i < j < k < nums.length
nums[i], nums[j], and nums[k] are pairwise distinct.
In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].
Return the number of triplets that meet the conditions.

Example 1:
Input: nums = [4,4,2,4,3]
Output: 3

Constraints:
3 <= nums.length <= 100
1 <= nums[i] <= 1000
*/

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        int left = 0;
        int right = nums.size();

        for (int num: nums) {
            mp[num]++;
        }

        if (mp.size() < 3) {
            return 0;
        }

        for (auto it: mp) {
            right -= it.second;
            res += left * it.second * right;
            left += it.second;
        }

        return res;
    }
};
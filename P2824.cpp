/*
2824. Count Pairs Whose Sum is Less than Target
Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.

Constraints:
1 <= nums.length == n <= 50
-50 <= nums[i], target <= 50
*/

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] < target) {
                    count++;
                }
            }
        }

        return count;
    }
};
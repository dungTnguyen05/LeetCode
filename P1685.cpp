/*
1685. Sum of Absolute Differences in a Sorted Array
You are given an integer array nums sorted in non-decreasing order.
Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.
In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

Constraints:
2 <= nums.length <= 105
1 <= nums[i] <= nums[i + 1] <= 104 
*/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> res(nums.size());
        int left = 0;
        int right = 0;

        for (auto num: nums) {
            right += num;
        }

        for (int i = 0; i < nums.size(); i++) {
            res[i] = (nums[i] * i - left) + (right - nums[i] * (nums.size() - i));
            left += nums[i];
            right -= nums[i];
        }

        return res;
    }
};
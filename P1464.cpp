/*
1464. Maximum Product of Two Elements in an Array
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

Constraints:
2 <= nums.length <= 500
1 <= nums[i] <= 10^3
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx1 = nums[nums.size() - 1];
        int mx2 = nums[nums.size() - 2];

        return (mx1 - 1) * (mx2 - 1);
    }
};
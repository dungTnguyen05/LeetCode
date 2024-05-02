/*
2441. Largest Positive Integer That Exists With Its Negative
Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
Return the positive integer k. If there is no such integer, return -1.

Constraints:
1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
nums[i] != 0
*/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = -1;

        for (int num: nums) {
            if (num > 0 && st.find(-num) != st.end()) {
                res = max(res, num);
            }
        }

        return res;
    }
};
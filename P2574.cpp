/*
2574. Left and Right Sum Differences
Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:
answer.length == nums.length.
answer[i] = |leftSum[i] - rightSum[i]|.

Where:
leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.

Return the array answer.

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 10^5
*/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // left_sum[i] + nums[i] + right_sum[i] = sum
        vector<int> res, left_sum, right_sum;
        left_sum.push_back(0);
        right_sum.push_back(sum - nums[0]);
        res.push_back(abs(left_sum[0] - right_sum[0]));

        for (int i = 1; i < nums.size(); i++) {
            left_sum.push_back(left_sum[i - 1] + nums[i - 1]);
            right_sum.push_back(sum - nums[i] - left_sum[i]);
            res.push_back(abs(left_sum[i] - right_sum[i]));
        }

        return res;
    }
};
/*
1991. Find the Middle Index in Array
Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).
A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].
If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.
Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

Constraints:
1 <= nums.length <= 100
-1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        //left_sum + nums[i] + right_sum = sum
        int left_sum = 0;
        int right_sum = sum - nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (left_sum == right_sum) {
                return i;
            }

            left_sum += nums[i];

            if (i != nums.size() - 1) {
                right_sum -= nums[i + 1];
            }

            else {
                right_sum = 0;
            }
        }

        return -1;
    }
};
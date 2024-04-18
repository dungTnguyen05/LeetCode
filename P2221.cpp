/*
2221. Find Triangular Sum of an Array
You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).
The triangular sum of nums is the value of the only element present in nums after the following process terminates:
1. Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.
2. For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
3. Replace the array nums with newNums.
4. Repeat the entire process starting from step 1.
Return the triangular sum of nums.

Example:
https://assets.leetcode.com/uploads/2022/02/22/ex1drawio.png

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 9
*/

// insight: ans = nC0 * nums[0] + nC1 * nums[1] + ... + nCn * nums[n - 1], where n = nums.size() - 1
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() != 1) {
            for (int i = 0; i < nums.size() - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }

            nums.pop_back();
        }

        return nums[0];
    }
};
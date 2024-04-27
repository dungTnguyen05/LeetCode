/*
2778. Sum of Squares of Special Elements
You are given a 1-indexed integer array nums of length n.
An element nums[i] of nums is called special if i divides n, i.e. n % i == 0.
Return the sum of the squares of all special elements of nums.

Example 1:
Input: nums = [1,2,3,4]
Output: 21
Explanation: There are exactly 3 special elements in nums: nums[1] since 1 divides 4, nums[2] since 2 divides 4, and nums[4] since 4 divides 4. 
Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21.  

Constraints:
1 <= nums.length == n <= 50
1 <= nums[i] <= 50
*/

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res = 0;
        
        for (int i = 1; i <= nums.size(); i++) {
            if (nums.size() % i == 0) {
                res += nums[i - 1] * nums[i - 1];
            }
        }

        return res;
    }
};
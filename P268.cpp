/*
268. Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2

Constraints:
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;

        for (int num: nums) {
            total += num;
        }

        return nums.size() * (nums.size() + 1)/2 - total;
    }
};
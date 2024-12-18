/*
260. Single Number III
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]

Example 3:
Input: nums = [0,1]
Output: [1,0]

Constraints:
2 <= nums.length <= 3 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/


// idea: XOR all numbers in nums, it will be the XOR of the 2 single numbers (because a ^ a = 0)
// now we need to find a bit that == 1, it is where num1 and num2 differ
// suppose it is the i-th bit in XOR of num1 ^ num2
// we can divide all numbers in nums in 2 parts: numbers that have bit 0 at i-th position and numbers that have bit 1 at i-th position
// now XOR the 2 parts, we get num1 and num2

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;

        for (int& num: nums) {
            XOR ^= num;
        }

        int i = 0;

        while (((XOR >> i) & 1) == 0) {
            i++;
        }

        int num1 = 0;
        int num2 = 0;

        for (int& num:nums) {
            if (((num >> i) & 1) == 0) {
                num1 ^= num;
            }

            else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};
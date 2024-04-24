/*
1979. Find Greatest Common Divisor of Array
Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

Constraints:
2 <= nums.length <= 1000
1 <= nums[i] <= 1000
*/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < mn) {
                mn = nums[i];
            }

            if (nums[i] > mx) {
                mx = nums[i];
            }
        }

        for (int i = min(mn, mx); i >= 1; i--) {
            if (mn % i == 0 && mx % i == 0) {
                return i;
            }
        }

        return 0;
    }
};
/*
2455. Average Value of Even Numbers That Are Divisible by Three
Given an integer array nums of positive integers, return the average value of all even integers that are divisible by 3.
Note that the average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 1000
*/

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total = 0;
        int count = 0;

        for (auto num: nums) {
            if (num % 6 == 0) {
                total += num;
                count++;
            }
        }

        if (count == 0) {
            return 0;
        }

        return total/count;
    }
};
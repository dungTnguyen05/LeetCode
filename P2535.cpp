/*
2535. Difference Between Element Sum and Digit Sum of an Array
You are given a positive integer array nums.
The element sum is the sum of all the elements in nums.
The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.
Note that the absolute difference between two integers x and y is defined as |x - y|.

Constraints:
1 <= nums.length <= 2000
1 <= nums[i] <= 2000
*/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element_sum = 0;
        int digit_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            element_sum += nums[i];
            string s = to_string(nums[i]);

            for (int j = 0; j < s.size(); j++) {
                digit_sum += s[j] - '0';
            }
        }

        return element_sum - digit_sum;
    }
};
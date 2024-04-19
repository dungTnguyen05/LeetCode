/*
724. Find Pivot Index
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.

Constraints:
1 <= nums.length <= 10^4
-1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
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
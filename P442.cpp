/*
442. Find All Duplicates in an Array
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.

Constraints:
n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;

        for (int num: nums) {
            int temp = abs(num);
            int idx = temp - 1;

            if (nums[idx] < 0) {
                res.push_back(temp);
            }

            else {
                nums[idx] *= -1;
            }
        }

        return res;
    }
};
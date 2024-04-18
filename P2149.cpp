/*
2149. Rearrange Array Elements by Sign
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
You should return the array of nums such that the the array follows the given conditions:
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Constraints:
2 <= nums.length <= 2 * 10^5
nums.length is even
1 <= |nums[i]| <= 10^5
nums consists of equal number of positive and negative integers.
 
It is not required to do the modifications in-place.
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> nums_pos, nums_neg, res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                nums_pos.push_back(nums[i]);
            }

            else {
                nums_neg.push_back(nums[i]);
            }
        }

        for (int i = 0; i < nums_pos.size(); i++) {
            res.push_back(nums_pos[i]);
            res.push_back(nums_neg[i]);
        }

        return res;
    }
};
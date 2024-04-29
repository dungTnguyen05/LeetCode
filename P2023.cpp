/*
2023. Number of Pairs of Strings With Concatenation Equal to Target
Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the concatenation of nums[i] + nums[j] equals target.

Constraints:
2 <= nums.length <= 100
1 <= nums[i].length <= 100
2 <= target.length <= 100
nums[i] and target consist of digits.
nums[i] and target do not have leading zeros.
*/

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int pairs = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && nums[i] + nums[j] == target) {
                    pairs++;
                }
            }
        }

        return pairs;
    }
};
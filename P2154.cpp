/*
2154. Keep Multiplying Found Values by Two
You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

You then do the following steps:
If original is found in nums, multiply it by two (i.e., set original = 2 * original).
Otherwise, stop the process.
Repeat this process with the new number as long as you keep finding the number.

Return the final value of original.

Example 1:
Input: nums = [5,3,6,1,12], original = 3
Output: 24

Constraints:
1 <= nums.length <= 1000
1 <= nums[i], original <= 1000
*/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int, int> mp;

        for (int num: nums) {
            mp[num]++;
        }

        while (mp.find(original) != mp.end()) {
            original *= 2;
        }

        return original;
    }
};
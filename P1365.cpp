/*
1365. How Many Numbers Are Smaller Than the Current Number
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
Return the answer in an array.

Example 1:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]

Constraints:
2 <= nums.length <= 500
0 <= nums[i] <= 100
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        int count[101] = {0};

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        for (int i = 1; i < 101; i++) {
            count[i] += count[i - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                res.push_back(0);
            }

            else {
                res.push_back(count[nums[i] - 1]);
            }
        }

        return res;
    }
};
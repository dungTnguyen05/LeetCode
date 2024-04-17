/*
2610. Convert an Array Into a 2D Array With Conditions
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.
Note that the 2D array can have a different number of elements on each row.

Example 1:
Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= nums.length
*/

// We need to determine the number of rows of the 2D vector => number of rows = maximum occurrence of a particular element 
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int max_freq = 1;
        int temp_freq = 1;
        int temp = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == temp) {
                temp_freq++;

                if (temp_freq > max_freq) {
                    max_freq = temp_freq;
                }
            }

            else {
                temp_freq = 1;
                temp = nums[i];
            }
        }

        vector<vector<int>> res(max_freq);
        temp = nums[0];
        int index = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == temp) {
                res[index].push_back(nums[i]);
                index++;
            }

            else {
                index = 0;
                res[index].push_back(nums[i]);
                temp = nums[i];
                index++;
            }
        }

        return res;
    }
};
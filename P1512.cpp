/*
1512. Number of Good Pairs
Given an array of integers nums, return the number of good pairs.
A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

// sort then count the frequency of each number
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        int count = 0;
        int x;

        sort(nums.begin(), nums.end());
        int temp = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == temp) {
                count++;

                if (i == nums.size() - 1) {
                    x = count * (count - 1);
                    x /= 2;
                    res += x;
                }
            }

            else {
                x = count * (count - 1);
                x /= 2;
                res += x;
                temp = nums[i];
                count = 1;
            }
        }

        return res;
    }
};
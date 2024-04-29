/*
2341. Maximum Number of Pairs in Array
You are given a 0-indexed integer array nums. In one operation, you may do the following:
Choose two integers in nums that are equal.
Remove both integers from nums, forming a pair.
The operation is done on nums as many times as possible.
Return a 0-indexed integer array answer of size 2 where answer[0] is the number of pairs that are formed and answer[1] is the number of leftover integers in nums after doing the operation as many times as possible.

Example 1:
Input: nums = [1,3,2,1,3,2,2]
Output: [3,1]

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        int pairs = 0;

        for (int num: nums) {
            mp[num]++;

            if (mp[num] % 2 == 0) {
                pairs++;
            }
        }

        res.push_back(pairs);
        res.push_back(nums.size() - 2 * pairs);

        return res;
    }
};
/*
2974. Minimum Number Game
You are given a 0-indexed integer array nums of even length and there is also an empty array arr. Alice and Bob decided to play a game where in every round Alice and Bob will do one move. The rules of the game are as follows:
Every round, first Alice will remove the minimum element from nums, and then Bob does the same.
Now, first Bob will append the removed element in the array arr, and then Alice does the same.
The game continues until nums becomes empty.
Return the resulting array arr.

Example 1:
Input: nums = [5,4,2,3]
Output: [3,2,5,4]

Constraints:
2 <= nums.length <= 100
1 <= nums[i] <= 100
nums.length % 2 == 0
*/

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i += 2) {
            arr.push_back(nums[i + 1]);
            arr.push_back(nums[i]);
        }

        return arr;
    }
};
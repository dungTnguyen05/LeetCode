/*
2357. Make Array Zero by Subtracting Equal Amounts
You are given a non-negative integer array nums. In one operation, you must:
Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.

Example 1:
Input: nums = [1,5,0,3,5]
Output: 3

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st;

        for (int num: nums) {
            if (num != 0) {
                st.insert(num);
            }
        }

        return st.size();
    }
};
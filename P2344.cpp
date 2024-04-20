/*
2344. Minimum Deletions to Make Array Divisible
You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.
Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. If this is not possible, return -1.
Note that an integer x divides y if y % x == 0.

Constraints:
1 <= nums.length, numsDivide.length <= 105
1 <= nums[i], numsDivide[i] <= 109
*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int gcd = numsDivide[0];
        int count = 0;

        for (int i = 1; i < numsDivide.size(); i++) {
            gcd = __gcd(gcd, numsDivide[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (gcd % nums[i] == 0) {
                return count;
            }

            else {
                count++;
            }
        }

        return -1;
    }
};
/*
1877. Minimize Maximum Pair Sum in Array
The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.
For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:
Each element of nums is in exactly one pair, and
The maximum pair sum is minimized.
Return the minimized maximum pair sum after optimally pairing up the elements.

Constraints:
n == nums.length
2 <= n <= 105
n is even.
1 <= nums[i] <= 105
*/

// ascending order: a_1 <= a_2 <= ... <= a_n => max(a_1 + a_n, a_2 + a_(n - 1), ...)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;

        for (int i = 0; i < nums.size()/2; i++) {
            if (nums[i] + nums[nums.size() - 1 - i] > res) {
                res = nums[i] + nums[nums.size() - 1 - i];
            }
        }

        return res;
    }
};
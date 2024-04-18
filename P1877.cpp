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

// intuition: 
// if we have 2 sums: a_i + a_j and a_k + a_l, where i < j < k < l (a_i <= a_j <= a_k <= a_l)
// we can minimize the maximum pair sum by reordering the sum to a_i + a_l and a_j + a_k (<= a_k + a_l)
// we can minimize until reaching a_1 + a_n, a_2 + a_(n - 1), ...

// concise proof (by contradiction):
// suppose we have the minimal maximum pair sum in a particular way, where a_i + a_j and a_k + a_l (i < j, k < l) are second max and max pair sum
// if j < k => i < j < k < l => like the intuition part
// if j > k => i < k < j < l (because a_i must < a_l) => reordering: a_i + a_l and a_j + a_k (<= a_k + a_l) 
// in both cases, we can generate new pair sums, where the maximum one is minimized 
// repeat until reaching a_1 + a_n, a_2 + a_(n - 1), ...

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
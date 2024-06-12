/*
1588. Sum of All Odd Length Subarrays
Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.
A subarray is a contiguous subsequence of the array.

Example 1:
Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58

Constraints:
1 <= arr.length <= 100
1 <= arr[i] <= 1000

Follow up:
Could you solve this problem in O(n) time complexity?
*/

// optimized solution: O(n) (count the number of times each element is included in the subarray)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;

        for (int i = 0; i < arr.size(); i++) {
            int left = i;
            int right = arr.size() - 1 - i;

            res += arr[i] * ((left/2) + 1) * ((right/2) + 1);
            res += arr[i] * ((left + 1)/2) * ((right + 1)/2);
        }

        return res;
    }
};
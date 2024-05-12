/*
2177. Find Three Consecutive Integers That Sum to a Given Number
Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.

Constraints:
0 <= num <= 10^15
*/

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3 == 0) {
            return {(num/3) - 1, num/3, (num/3) + 1};
        }

        return {};
    }
};
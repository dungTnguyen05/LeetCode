/*
2358. Maximum Number of Groups Entering a Competition
You are given a positive integer array grades which represents the grades of students in a university. You would like to enter all these students into a competition in ordered non-empty groups, such that the ordering meets the following conditions:
The sum of the grades of students in the ith group is less than the sum of the grades of students in the (i + 1)th group, for all groups (except the last).
The total number of students in the ith group is less than the total number of students in the (i + 1)th group, for all groups (except the last).
Return the maximum number of groups that can be formed.

Example 1:
Input: grades = [10,6,12,7,3,5]
Output: 3

Constraints:
1 <= grades.length <= 10^5
1 <= grades[i] <= 10^5
*/

// greedy approach: sort array in ascending order, and then for the 1st group: 1 element, 2nd group: 2 elements, and so on.
// => find max x: 1 + ... + x <= n
// solve the quadratic equation: x(x + 1) = 2n
// (2x + 1)^2 = 8n + 1
// x = (sqrt(8n + 1) - 1)/2;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        return (sqrt(8 * grades.size() + 1) - 1)/2;
    }
};
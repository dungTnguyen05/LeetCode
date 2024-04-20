/*
1551. Minimum Operations to Make Array Equal
You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i (i.e., 0 <= i < n).
In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] (i.e., perform arr[x] -=1 and arr[y] += 1). The goal is to make all the elements of the array equal. It is guaranteed that all the elements of the array can be made equal using some operations.
Given an integer n, the length of the array, return the minimum number of operations needed to make all the elements of arr equal.

Constraints:
1 <= n <= 10^4
*/

/*
insight: after each operation, the sum of all numbers does not change and is equal to 1 + 3 + ... + (2 * n - 1) = n^2 
=> when the operations end, each number is equal to n
we perform operations on arr[i] and arr[j], where i + j = n - 1
=> minimum number of operations:
1. when n % 2 == 0 => (n - 1) + (n - 3) + ... + 1 = n^2/4
2. when n % 2 == 1 => (n - 1) + (n - 3) + ... + 0 = (n^2 - 1)/4
*/

class Solution {
public:
    int minOperations(int n) {
        if (n % 2 == 0) {
            return pow(n, 2)/4;
        }

        return (pow(n, 2) - 1)/4 ;
    }
};
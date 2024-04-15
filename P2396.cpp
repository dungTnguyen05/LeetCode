/*
2396. Strictly Palindromic Number
An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), the string representation of the integer n in base b is palindromic.
Given an integer n, return true if n is strictly palindromic and false otherwise.
A string is palindromic if it reads the same forward and backward.

Constraints:
4 <= n <= 105
*/

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        // n in base n - 2 = 1 * (n - 2)^1 + 2 * (n - 2)^0 = 12 when n > 4
        // 4 in base 2 = 100
        return false;
    }
};
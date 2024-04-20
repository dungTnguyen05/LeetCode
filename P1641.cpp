/*
1641. Count Sorted Vowel Strings
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

Constraints:
1 <= n <= 50 
*/

// Euler's candy division problem ((n + 5 - 1)C(5 - 1))
class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 1) * (n + 2) * (n + 3) * (n + 4)/24;
    }
};
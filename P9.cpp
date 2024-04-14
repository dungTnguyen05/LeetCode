/*
9. Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != a[a.size() - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};
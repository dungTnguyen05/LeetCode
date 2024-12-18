/*
1318. Minimum Flips to Make a OR b Equal to c
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

Example 1:
https://assets.leetcode.com/uploads/2020/01/06/sample_3_1676.png
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

Example 2:
Input: a = 4, b = 2, c = 7
Output: 1

Example 3:
Input: a = 1, b = 2, c = 3
Output: 0

Constraints:
1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9
*/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while (a != 0 || b != 0 || c != 0) {
            if ((c & 1) == 1) { // extract the LSB of c
                if ((a & 1) == 0 && (b & 1) == 0) { // extract the LSB of a and b
                    flips++;
                }
            }

            else {
                if ((a & 1) == 1 && (b & 1) == 1) {
                    flips += 2;
                }

                else if ((a & 1) == 1 || (b & 1) == 1) {
                    flips++;
                }
            }

            a >>= 1; // shift a right by 1 bit
            b >>= 1; // shift b right by 1 bit
            c >>= 1; // shift c right by 1 bit
        }

        return flips;
    }
};
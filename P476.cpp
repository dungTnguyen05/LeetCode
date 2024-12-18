/*
476. Number Complement 
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

Example 1:
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

Constraints:
1 <= num < 2^31
*/

class Solution {
public:
    int findComplement(int num) {
        int i = 0;
        int res = 0;

        while (num >> i) { // continue while there are bits to process
            if (((num >> i) & 1) == 0) {
                res |= (1 << i); // also res = res | (1 << i): means res OR 00..00100..00 (i times 0 after 1)
            }

            i++;
        }

        return res;
    }
};

// other way: a binary number plus its complement will equal 111....111 in binary.
// return ((1 << MSB) - 1) ^ num, where MSB = log2(num) + 1;
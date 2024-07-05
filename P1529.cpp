/*
1529. Minimum Suffix Flips
You are given a 0-indexed binary string target of length n. You have another binary string s of length n that is initially set to all zeros. You want to make s equal to target.
In one operation, you can pick an index i where 0 <= i < n and flip all bits in the inclusive range [i, n - 1]. Flip means changing '0' to '1' and '1' to '0'.
Return the minimum number of operations needed to make s equal to target.

Example 1:
Input: target = "10111"
Output: 3
Explanation: Initially, s = "00000".
Choose index i = 2: "00000" -> "00111"
Choose index i = 0: "00111" -> "11000"
Choose index i = 1: "11000" -> "10111"
We need at least 3 flip operations to form target.

Example 2:
Input: target = "101"
Output: 3
Explanation: Initially, s = "000".
Choose index i = 0: "000" -> "111"
Choose index i = 1: "111" -> "100"
Choose index i = 2: "100" -> "101"
We need at least 3 flip operations to form target.

Example 3:
Input: target = "00000"
Output: 0
Explanation: We do not need any operations since the initial s already equals target.

Constraints:
n == target.length
1 <= n <= 10^5
target[i] is either '0' or '1'.
*/

// insight: every time we flip a bit, we also flip all the bits to the right of it.
// therefore, we need to consider when the bit comes from 0 to 1, and vice versa.
// every time the parity changes, it means that the left bit needs 1 more flip.
class Solution {
public:
    int minFlips(string target) {
        int count = 0;

        for (char& c: target) {
            if ((count + (c - '0')) % 2 == 1) {
                count++;
            }
        }

        return count;
    }
};
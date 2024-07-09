/*
1217. Minimum Cost to Move Chips to The Same Position
We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:
position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.

Return the minimum cost needed to move all the chips to the same position. 

Example 1:
https://assets.leetcode.com/uploads/2020/08/15/chips_e1.jpg
Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.

Example 2:
https://assets.leetcode.com/uploads/2020/08/15/chip_e2.jpg
Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.

Example 3:
Input: position = [1,1000000000]
Output: 1

Constraints:
1 <= position.length <= 100
1 <= position[i] <= 10^9
*/

// insight: parity
// chip from even position can be moved to any even position with cost 0
// chip from odd position can be moved to any odd position with cost 0
// chip from even position can be moved to any odd position with cost 1
// chip from odd position can be moved to any even position with cost 1
// therefore, we only need to count the number of chips in even and odd positions
// the minimum cost is the minimum of the two counts
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even_pos = 0;
        int odd_pos = 0;

        for (int& pos: position) {
            if (pos % 2 == 0) {
                even_pos++;
            }

            else {
                odd_pos++;
            }
        }

        return min(even_pos, odd_pos);
    }
};
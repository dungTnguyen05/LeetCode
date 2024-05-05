/*
1753. Maximum Score From Removing Stones
You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ respectively. Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score. The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).
Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.

Example 1:
Input: a = 2, b = 4, c = 6
Output: 6
Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
- Take from 1st and 3rd piles, state is now (1, 4, 5)
- Take from 1st and 3rd piles, state is now (0, 4, 4)
- Take from 2nd and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 6 points.

Example 2:
Input: a = 4, b = 4, c = 6
Output: 7
Explanation: The starting state is (4, 4, 6). One optimal set of moves is:
- Take from 1st and 2nd piles, state is now (3, 3, 6)
- Take from 1st and 3rd piles, state is now (2, 3, 5)
- Take from 1st and 3rd piles, state is now (1, 3, 4)
- Take from 1st and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 7 points.

Example 3:
Input: a = 1, b = 8, c = 8
Output: 8
Explanation: One optimal set of moves is to take from the 2nd and 3rd piles for 8 turns until they are empty.
After that, there are fewer than two non-empty piles, so the game ends.
 
Constraints:
1 <= a, b, c <= 10^5
*/

// WLOG, a < b < c
// If a + b < c, what ever pair of piles you choose, these 2 would have a or b => a or b always decrement => res = a + b

// If a + b = c, result would also be a + b (or c or (a + b + c)/2)

// If a + b > c, we need to consider c - b vs. a. Optimal way is to choose a and b until c - b = a (or the difference between them is 1).
// As a and b are choosen, c - b will increment, and a will decrement, which means that c - b and a can be as equal as possible.

// If c - b and a have the same parity, we choose a and b (a + b - c)/2 times. Now we have 3 numbers: x, x, 2x => we can do it 2x times, which is the value of c after choosing a and b (a + b - c)/2 times).
// => res = (a + b - c)/2 + c = (a + b + c)/2.

// If c - b and a do not have the same parity, we can apply the previous idea, and due to round off for int in C++, the res would also be (a + b + c)/2.

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int mx = max(max(a, b), c);
        int mn = min(min(a, b), c);
        int mid = a + b + c - mx - mn;

        if (mn + mid < mx) {
            return mn + mid;
        }

        return (a + b + c)/2;
    }
};
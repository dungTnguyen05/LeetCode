/*
1025. Divisor Game 
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
Choosing any x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.

Constraints:
1 <= n <= 1000
*/

// if n % 2 == 0, Alice can take x as 1, then n = n - 1, which is an odd number. 
// From now on, when it's Alice's turn, it's even, when it's Bob's turn, it's odd.
// The game continues till it comes to 1, which is Bob's turn. He loses.
class Solution {
public:
    bool divisorGame(int n) {
        if (n % 2 == 0) {
            return true;
        }

        return false;
    }
};
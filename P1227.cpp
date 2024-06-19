/*
1227. Airplane Seat Assignment Probability
n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of the passengers will:
+ Take their own seat if it is still available, and
+ Pick other seats randomly when they find their seat occupied
Return the probability that the nth person gets his own seat.

Example 1:
Input: n = 1
Output: 1.00000
Explanation: The first person can only get the first seat.

Example 2:
Input: n = 2
Output: 0.50000
Explanation: The second person has a probability of 0.5 to get the second seat (when first person gets the first seat).

Constraints:
1 <= n <= 10^5
*/

// If the 1st passenger choose a correct seat => OK.
// If not, he will choose x-th passenger's seat => 2nd to (x - 1)-th passenger will still have correct seats. 
// Now, x-th passenger will have 2 options: choose 1st passenger's seat, or another one.
// If he choose the 1st passenger's seat => everyone after him will have their correct seats (including the last one).
// Else, he choose the y-th passenger's seat => (x + 1)-th passenger to (y - 1)-th passenger will still have correct seats.
// We see a pattern here, if the person who is taken his/her correct seat, he/she can take the person-take-his/her-seat'seat, or choose another one.
// For the former, everything will ok for the rest. If not, we just repeat the process.
// Therefore, the answer is 1/2.

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n == 1) {
            return 1;
        }

        return 0.5;
    }
};
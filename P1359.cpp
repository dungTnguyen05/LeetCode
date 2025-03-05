/*
1359. Count All Valid Pickup and Delivery Options
Given n orders, each order consists of a pickup and a delivery service.
Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.

Example 2:
Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.

Example 3:
Input: n = 3
Output: 90

Constraints:
1 <= n <= 500
*/

/*
n = 1 => 1
n = 2 => fix P1 and D1 (D1 after P1) => P2 before P1 (3 ways for D2), P2 between P1 and D1 (2 ways for D2), P2 after D1 (1 way for D2) => 1 + 2 + 3 = 3 * 4 / 2 = 4!/2^2
n = 3 => fix P1, D1, P2, D2 => P3 before all (5 ways for D3), P3 after 1 of these and before 3 of these (4 ways for D3), P3 after 2 of these and before 2 of these (3 ways for D3), P3 after 3 of these and before 1 of these (2 ways for D3), P3 after all of these (1 way for D3) => (1 + 2 + 3)(1 + 2 + 3 + 4 + 5) = (3 * 4 / 2) * (5 * 6 / 2) = 6!/2^3
=> formula: (2n)!/2^n
*/
class Solution {
public:
    int countOrders(int n) {
        long long res = 1;
        int mod = 1e9 + 7;

        for (int i = 1; i <= n; i++) {
            res *= i * (2 * i - 1);
            res %= mod;
        }

        return res;
    }
};
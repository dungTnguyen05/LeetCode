/*
1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
The Fibonacci numbers are defined as:
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 for n > 2.
It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.

Example 1:
Input: k = 7
Output: 2 
Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
For k = 7 we can use 2 + 5 = 7.
 
Constraints:
1 <= k <= 10^9
*/

// approach: as Fibonacci numbers are sum of some previous Fibonacci numbers, we should use Greedy algorithm to achieve the minimum number of Fibonacci numbers needed.
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibo = {1, 1};
        int count = 0;
        while (fibo.back() < k) {
            fibo.push_back(fibo[fibo.size() - 1] + fibo[fibo.size() - 2]);
        }

        while (k > 0) {
            for (int i = fibo.size() - 1; i >= 0; i--) {
                if (fibo[i] <= k) {
                    int temp = k/fibo[i];
                    count += temp;
                    k -= temp * fibo[i];
                    break;
                }
            }
        }

        return count;
    }
};
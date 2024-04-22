/*
1735. Count Ways to Make Array With Product
You are given a 2D integer array, queries. For each queries[i], where queries[i] = [ni, ki], find the number of different ways you can place positive integers into an array of size ni such that the product of the integers is ki. As the number of ways may be too large, the answer to the ith query is the number of ways modulo 10^9 + 7.
Return an integer array answer where answer.length == queries.length, and answer[i] is the answer to the ith query.

Example 1:
Input: queries = [[2,6],[5,1],[73,660]]
Output: [4,1,50734910]
Explanation: Each query is independent.
[2,6]: There are 4 ways to fill an array of size 2 that multiply to 6: [1,6], [2,3], [3,2], [6,1].
[5,1]: There is 1 way to fill an array of size 5 that multiply to 1: [1,1,1,1,1].
[73,660]: There are 1050734917 ways to fill an array of size 73 that multiply to 660. 1050734917 modulo 109 + 7 = 50734910.

Example 2:
Input: queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: [1,2,3,10,5]

Constraints:
1 <= queries.length <= 10^4 
1 <= ni, ki <= 10^4
*/

// insight: factorize + stars and bars problem (aka Euler's candy division problem)

class Solution {
public:
    bool is_prime(int n) {
        if (n <= 1) {
            return false;
        }

        if (n == 2) {
            return true;
        }

        if (n % 2 == 0) {
            return false;
        }

        for (int i = 3; i < sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int combination(int n, int k) {
        if (k == 0 || k == n) {
            return 1;
        }

        return combination(n - 1, k - 1) + combination(n - 1, k);
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> res(queries.size(), 1);
        int mod = 1e9 + 7;
        int p = 2;
        int count = 0;

        while (count != queries.size()) {
            count = 0;

            if (is_prime(p) == true) {
                for (int i = 0; i < queries.size(); i++) {
                    int temp = 0;

                    if (queries[i][1] == 1) {
                        count++;
                    }

                    else {
                        while (queries[i][1] % p == 0) {
                            queries[i][1] /= p;
                            temp++;
                        }

                        res[i] = long(res[i]) * combination(temp + queries[i][0] - 1, queries[i][0] - 1) % mod;
                    }
                }
            }

            if (p > 2) {
                p += 2;
            }

            else {
                p++;
            }
        }

        return res;
    }
};

//or:

class Solution {
public:
    bool is_prime(int n) {
        if (n <= 1) {
            return false;
        }

        if (n == 2) {
            return true;
        }

        if (n % 2 == 0) {
            return false;
        }

        for (int i = 3; i < sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> res(queries.size(), 1);
        int comb[10013][14] = {1};
        int mod = 1e9 + 7;
        int p = 2;
        int count = 0;

        for (int i = 1; i < 10013; i++) {
            for (int j = 0; j < 14; j++) {
                if (j == 0 || j == i) {
                    comb[i][j] = 1;
                }

                else {
                    comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
                }
            }
        }

        while (count != queries.size()) {
            count = 0;

            if (is_prime(p) == true) {
                for (int i = 0; i < queries.size(); i++) {
                    int temp = 0;

                    if (queries[i][1] == 1) {
                        count++;
                    }

                    else {
                        while (queries[i][1] % p == 0) {
                            queries[i][1] /= p;
                            temp++;
                        }

                        res[i] = long(res[i]) * comb[temp + queries[i][0] - 1][temp] % mod;
                    }
                }
            }

            if (p > 2) {
                p += 2;
            }

            else {
                p++;
            }
        }

        return res;
    }
};
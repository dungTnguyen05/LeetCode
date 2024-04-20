/*
1806. Minimum Number of Operations to Reinitialize a Permutation
You are given an even integer n​​​​​​. You initially have a permutation perm of size n​​ where perm[i] == i​ (0-indexed)​​​​.

In one operation, you will create a new array arr, and for each i:
If i % 2 == 0, then arr[i] = perm[i / 2].
If i % 2 == 1, then arr[i] = perm[n / 2 + (i - 1) / 2].

You will then assign arr​​​​ to perm.

Return the minimum non-zero number of operations you need to perform on perm to return the permutation to its initial value.

Constraints:
2 <= n <= 1000
n​​​​​​ is even.
*/

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm, arr, old_arr;
        int opers = 1;

        for (int i = 0; i < n; i++) {
            perm.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                arr.push_back(perm[i/2]);
            }

            else {
                arr.push_back(perm[(n/2) + (i - 1)/2]);
            }
        }

        while (perm != arr) {
            old_arr = arr;
            arr.clear();

            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    arr.push_back(old_arr[i/2]);
                }

                else {
                    arr.push_back(old_arr[(n/2) + (i - 1)/2]);
                }
            }

            opers++;
        }

        return opers;
    }
};
/*
1460. Make Two Arrays Equal by Reversing Subarrays
You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.
Return true if you can make arr equal to target or false otherwise.

Constraints:
target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000
*/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        for (int i = 0; i < target.size(); i++) {
            if (target[i] != arr[i]) {
                return false;
            }
        }

        return true;
    }
};
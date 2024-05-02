/*
1122. Relative Sort Array
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

Constraints:
1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        vector<int> res;
        vector<int> temp;

        for (int num: arr1) {
            mp[num]++;
        }

        for (int num: arr2) {
            while (mp[num] != 0) {
                res.push_back(num);
                mp[num]--;
            }
        }

        for (int num: arr1) {
            if (mp[num] != 0) {
                temp.push_back(num);
            }
        }

        sort(temp.begin(), temp.end());
        res.insert(res.end(), temp.begin(), temp.end());

        return res;
    }
};
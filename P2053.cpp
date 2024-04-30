/*
2053. Kth Distinct String in an Array
A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.

Example 1:
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"

Constraints:
1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.
*/

/*
2053. Kth Distinct String in an Array
A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.

Example 1:
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"

Constraints:
1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.
*/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        int count = 0;

        for (auto s: arr) {
            mp[s]++;
        }

        for (auto s: arr) {
            if (mp[s] == 1) {
                count++;
            }

            if (count == k) {
                return s;
            }
        }

        return "";
    }
};
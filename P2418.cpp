/*
2418. Sort the People
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
For each index i, names[i] and heights[i] denote the name and height of the ith person.
Return names sorted in descending order by the people's heights.

Example 1:
Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

Constraints:
n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.
*/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        vector<string> res;

        for (int i = 0; i < names.size(); i++) {
            mp[heights[i]] = names[i];
        }

        for (auto it: mp) {
            res.push_back(it.second);
        }

        reverse(res.begin(), res.end()); // if we do not want to reverse, try for (auto it = mp.rbegin(); it != rend(); it++) in the for loop above

        return res;
    }
};

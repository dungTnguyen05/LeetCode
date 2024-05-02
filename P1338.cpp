/*
1338. Reduce Array Size to The Half
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
Return the minimum size of the set so that at least half of the integers of the array are removed.

Example 1:
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.

Constraints:
2 <= arr.length <= 105
arr.length is even.
1 <= arr[i] <= 105
*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        int removed = 0;
        int count = 0;

        for (int num: arr) {
            mp[num]++;
        }

        for (auto it: mp) {
            pq.push(it.second);
        }

        while (2 * removed < arr.size() && !pq.empty()) {
            removed += pq.top();
            count++;
            pq.pop();
        }

        return count;
    }
};
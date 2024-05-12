/*
171. Excel Sheet Column Number
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

Constraints:
1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
*/

// approach: base 26
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int power = columnTitle.size() - 1;

        for (int i = 0; i < columnTitle.size(); i++) {
            res += (columnTitle[i] - 'A' + 1) * pow(26, power);
            power--;
        }

        return res;
    }
};
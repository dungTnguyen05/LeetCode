/*
1678. Goal Parser Interpretation
You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.
Given the string command, return the Goal Parser's interpretation of command.

Constraints:
1 <= command.length <= 100
command consists of "G", "()", and/or "(al)" in some order.
*/

class Solution {
public:
    string interpret(string command) {
        string res = "";
        int i = 0;

        while (i != command.size()) {
            if (command[i] == 'G') {
                res += 'G';
                i++;
            }

            else {
                if (command[i + 1] == ')') {
                    res += 'o';
                    i += 2;
                }

                else {
                    res += "al";
                    i += 4;
                }
            }
        }

        return res;
    }
};
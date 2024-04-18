/*
1108. Defanging an IP Address
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".

Constraints:
The given address is a valid IPv4 address.
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string res;

        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                res += "[.]";
            }

            else {
                res += address[i];
            }
        }

        return res;
    }
};
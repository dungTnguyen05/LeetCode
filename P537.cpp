/*
537. Complex Number Multiplication
A complex number can be represented as a string on the form "real+imaginaryi" where:
real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i^2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

Example 1:
Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i^2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i^2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 
Constraints:
num1 and num2 are valid complex numbers.
*/

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a, b, c, d;
        char buffer;
        
        // parse the input strings
        stringstream ss1(num1), ss2(num2);
        ss1 >> a >> buffer >> b >> buffer; // parse num1 into real (a) and imaginary (b) parts
        ss2 >> c >> buffer >> d >> buffer; // parse num2 into real (c) and imaginary (d) parts
        
        int realPart = a * c - b * d;
        int imaginaryPart = a * d + b * c;
        
        return to_string(realPart) + "+" + to_string(imaginaryPart) + "i";
    }
};
/*
1344. Angle Between Hands of a Clock
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
Answers within 10^(-5) of the actual value will be accepted as correct.

Constraints:
1 <= hour <= 12
0 <= minutes <= 59
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        int minute_degree = 6 * minutes;
        double hour_degree = 30 * hour + 0.5 * minutes;
        return min(abs(hour_degree - minute_degree), 360 - abs(hour_degree - minute_degree));
    }
};
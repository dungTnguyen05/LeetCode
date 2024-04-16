/*
1402. Reducing Dishes
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Constraints:
n == satisfaction.length
1 <= n <= 500
-1000 <= satisfaction[i] <= 1000
*/

// choose from high to low satisfactions
// if a negative satisfaction is considered, compare it with the sum of all higher satisfactions

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        if (satisfaction.back() < 0) {
            return 0;
        }

        int sum = 0;
        int index;

        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            sum += satisfaction[i];

            if (sum < 0) {
                sum -= satisfaction[i];
                index = i + 1;
                break;
            }
        }

        int res = 0;
        int time = 1;

        for (int i = index; i < satisfaction.size(); i++) {
            res += time * satisfaction[i];
            time++;
        }

        return res;
    }
};
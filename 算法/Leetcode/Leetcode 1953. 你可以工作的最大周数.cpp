#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:

    long long numberOfWeeks(vector<int>& milestones) {
        long long sz = milestones.size(), sum = 0;
        sort(milestones.begin(), milestones.end());
        for (int i = 0; i < sz - 1; i++) {
            sum += milestones[i];
        }
        if (sum < milestones[sz - 1] - 1) {
            return 2 * sum + 1;
        }
        return sum + milestones[sz - 1];;
    }

};
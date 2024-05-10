#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int res = 0;
        int now = 0;
        for (int i = 0; i < batteryPercentages.size(); i++) {
            if (batteryPercentages[i] - now > 0) {
                res++;
                now++;
            }
        }
        return res;
    }
};
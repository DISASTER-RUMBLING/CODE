#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int times = 0;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] >= target) {
                times++;
            }
        }
        return times;
    }
};
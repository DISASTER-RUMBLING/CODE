#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double now = 0, res;
        for (int i = 0; i < k; i++) {
            now += nums[i];
        }
        now = now / k;
        res = now;
        for (int i = k; i < nums.size(); i++) {
            now += (double)((nums[i] - nums[i - k]) / (k * 1.0));
            res = max(now, res);
        }
        return res;
    }
};
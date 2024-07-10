#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sum(1 + nums.size(), 0);
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 1; i < sum.size(); i++) {
            if ((sum[i] - nums[i - 1]) * 2 == sum[nums.size()] - nums[i - 1]) {
                return i - 1;
            }
        }
        return -1;
    }
};
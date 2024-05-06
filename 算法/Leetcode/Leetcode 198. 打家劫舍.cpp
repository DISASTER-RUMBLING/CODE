#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }
        vector<int> res(nums.size());
        res[0] = nums[0];
        res[1] = max(nums[1], res[0]);
        for (int i = 2; i < nums.size(); i++) {
            res[i] = max(res[i - 1], res[i - 2] + nums[i]);
        }
        return res[nums.size() - 1];
    }
};
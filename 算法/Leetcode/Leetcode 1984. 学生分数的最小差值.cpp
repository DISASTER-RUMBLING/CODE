#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        int res = 10000000;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - k + 1; i++) {
            res = min(res, (nums[i + k - 1] - nums[i]));
        }
        return res;
    }
};
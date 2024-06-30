#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> mmp(k, vector<int>(k));
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] %= k;
            for (int j = 0; j < k; j++) {
                mmp[j][nums[i]] = mmp[nums[i]][j] + 1;
                res = max(res, mmp[j][nums[i]]);
            }
        }
        return res;
    }
};
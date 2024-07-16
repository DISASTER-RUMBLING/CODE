#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int ans = 2 * k + 1;
        long long now = 0;
        vector<int> res(nums.size(), -1);
        if (ans > nums.size()) {
            return res;
        }
        for (int i = 0; i < ans; i++) {
            now += nums[i];
        }
        for (int i = ans; i < nums.size(); i++) {
            res[i - k - 1] = now / ans;
            now += (nums[i] - nums[i - ans]);
        }
        res[nums.size() - k - 1] = now / ans;
        return res;
    }
};
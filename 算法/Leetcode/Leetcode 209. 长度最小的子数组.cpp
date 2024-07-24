#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, ans = 0, sz = nums.size(), res = sz + 1;
        for (int r = 0; r < sz; r++) {
            ans += nums[r];
            while (ans >= target) {
                res = min(res, r - l + 1);
                ans -= nums[l];
                l++;
            }
        }
        return res == (sz + 1) ? 0 : res;
    }
};
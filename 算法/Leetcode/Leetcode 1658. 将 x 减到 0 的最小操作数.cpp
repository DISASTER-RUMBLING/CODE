#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0, sum = 0, ans = 0, sz = nums.size(), res = -1;
        for (int i = 0; i < sz; i++) {
            sum += nums[i];
        }
        sum -= x;
        if (sum < 0) {
            return -1;
        }
        else if (!sum) {
            return sz;
        }
        for (int i = 0; i < sz; i++) {
            ans += nums[i];
            while (ans > sum && l < i) {
                ans -= nums[l];
                l++;
            }
            if (ans == sum) {
                res = max(res, i - l + 1);
            }
        }
        return res < 0 ? -1 : sz - res;
    }
};
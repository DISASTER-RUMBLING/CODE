#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    bool Check(vector<int>& nums, int mid) {
        long long num = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            if (nums[i] > mid) {
                if (nums[i] - num > mid) {
                    return false;
                }
                num -= (nums[i] - mid);
            }
            else {
                num += (mid - nums[i]);
            }
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            r = max(r, nums[i]);
        }
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (Check(nums, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};
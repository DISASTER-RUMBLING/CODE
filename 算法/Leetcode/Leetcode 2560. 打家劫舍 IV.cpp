#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    bool Check(vector<int>& nums, int k, int mid) {
        int sz = nums.size();
        int f0 = 0, f1 = 0;
        for (int i = 0; i < sz; i++) {
            if (nums[i] > mid) {
                f0 = f1;
            }
            else {
                int tmp = f1;
                f1 = max(f1, f0 + 1);
                f0 = tmp;
            }
        }
        return f1 >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int r = 0, sz = nums.size(), l = 0;
        for (int i = 0; i < sz; i++) {
            r = max(nums[i], r);
        }
        r++;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (Check(nums, k, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};
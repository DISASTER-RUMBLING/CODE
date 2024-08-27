#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    bool Check(vector<int>& nums, int maxOperations, int mid) {
        int res = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            res += (nums[i] / mid);
            if (0 == nums[i] % mid) {
                res--;
            }
            if (res > maxOperations) {
                return false;
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 0, r = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            r = max(r, nums[i]);
        }
        r++;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (Check(nums, maxOperations, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};
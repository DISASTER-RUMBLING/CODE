#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    bool Check(vector<int>& nums, int p, int mid) {
        int res = 0, sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            if (nums[i + 1] - nums[i] <= mid) {
                res++;
                i++;
            }
        }
        return res >= p ? true : false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = -1, r = nums[nums.size() - 1];
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (Check(nums, p, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};
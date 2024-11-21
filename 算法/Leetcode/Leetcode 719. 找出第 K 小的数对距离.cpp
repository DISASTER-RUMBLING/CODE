#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:

    bool Check(vector<int>& nums, int k, int mid) {
        int l = 0, r = 1, sz = nums.size(), num = 0;
        for (l = 0; l < sz; l++) {
            while (r < sz && nums[r] - nums[l] < mid) {
                r++;
            }
            num += (r - l - 1);
        }
        return num < k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sz = nums.size(), l = 0, r = nums[sz - 1] - nums[0] + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (Check(nums, k, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, l = 0, ans = 1, sz = nums.size();
        for (int r = 0; r < sz; r++) {
            ans *= nums[r];
            while (ans >= k && l <= r) {
                ans = ans / nums[l++];
            }
            res += (r - l + 1);
        }
        return res;
    }
};
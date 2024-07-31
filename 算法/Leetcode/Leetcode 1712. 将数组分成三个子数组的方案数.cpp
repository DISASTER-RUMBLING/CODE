#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    int waysToSplit(vector<int>& nums) {
        int sz = nums.size(), res = 0, mod = 1e9 + 7, l = 0, r = 0;
        for (int i = 1; i < sz; i++) {
            nums[i] += nums[i - 1];
        }
        for (int i = 0; i <= sz - 2; i++) {
            l = max(i + 1, l);
            while (l < sz && (nums[l] - nums[i]) < nums[i]) {
                l++;
            }
            r = max(r, l);
            while (r < sz - 1 && (nums[r] - nums[i]) <= (nums[sz - 1] - nums[r])) {
                r++;
            }
            if (r >= l) {
                res = (res + r - l) % mod;
            }
        }
        return res;
    }

};
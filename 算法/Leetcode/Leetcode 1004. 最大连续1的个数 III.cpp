#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, res = 0, sz = nums.size(), times = 0;
        while (r < sz) {
            if (nums[r] == 0) {
                times++;
            }
            while (times > k) {
                if (nums[l] == 0) {
                    times--;
                }
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
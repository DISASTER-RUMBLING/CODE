#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 0, res = 1, sz = nums.size();
        while (r < sz) {
            for (int i = l; i < r; i++) {
                if ((nums[i] & nums[r]) != 0) {
                    l = i + 1;
                }
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
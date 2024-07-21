#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            int ans = 0, flag = 1, now = i, pos = -1;
            while (now < sz && (flag || nums[now] == 1)) {
                if (!nums[now]) {
                    flag = 0;
                    pos = now;
                }
                else {
                    ans++;
                }
                now++;
            }
            if (!flag) {
                res = max(res, ans);
                i = pos;
            }
            else {
                res = max(res, ans - 1);
            }
        }
        return res;
    }
};
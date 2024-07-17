#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int res = 100000, ans = 0, now = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                now++;
            }
        }
        for (int i = 0; i < now; i++) {
            if (!nums[i]) {
                ans++;
            }
        }
        for (int i = now; i < nums.size() + now; i++) {
            res = min(res, ans);
            if (!nums[(i - now) % nums.size()]) {
                ans--;
            }
            if (!nums[i % nums.size()]) {
                ans++;
            }
        }
        res = min(res, ans);
        return res;
    }
};
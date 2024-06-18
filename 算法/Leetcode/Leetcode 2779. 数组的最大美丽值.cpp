#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    int maximumBeauty(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int l = 0, sz = nums.size(), r = 0;
        while (l < sz - 1) {
            int num = nums[l], ans = 0;
            while (r < sz) {
                if ((nums[r] - nums[l]) <= (2 * k)) {
                    ans = max(r - l + 1, ans);
                    r++;
                }
                else {
                    break;
                }
            }
            res = max(ans, res);
            l++;
        }
        return res == 0 ? 1 : res;
    }

};
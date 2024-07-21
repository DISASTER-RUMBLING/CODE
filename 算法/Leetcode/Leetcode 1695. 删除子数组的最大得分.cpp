#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, bool> mmp;
        int ans = 0, res = 0, sz = nums.size(), l = 0;
        for (int r = 0; r < sz; r++) {
            if (!mmp[nums[r]]) {
                ans += nums[r];
                mmp[nums[r]] += 1;
            }
            else {
                while (mmp[nums[r]] == 1) {
                    mmp[nums[l]] -= 1;
                    ans -= nums[l];
                    l++;
                }
                mmp[nums[r]] += 1;
                ans += nums[r];
            }
            res = max(res, ans);
        }
        return res;
    }
};
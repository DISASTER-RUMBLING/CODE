#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0, l = 0, sz = nums.size(), ans = 0;
        map<int, int> mmp;
        for (long long r = 0; r < sz; r++) {
            mmp[nums[r]] += 1;
            ans += (mmp[nums[r]] - 1);
            while (ans >= k) {
                res += (sz - r);
                ans -= (mmp[nums[l]] - 1);
                mmp[nums[l]] -= 1;
                l++;
            }
        }
        return res;
    }
};
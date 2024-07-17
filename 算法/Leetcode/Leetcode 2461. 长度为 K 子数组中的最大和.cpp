#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, ans = 0, use = 0;
        map<int, int> mmp;
        for (int i = 0; i < k; i++) {
            ans += nums[i];
            if (mmp[nums[i]]) {
                use++;
            }
            mmp[nums[i]]++;
        }
        for (int i = k; i < nums.size(); i++) {
            if (!use) {
                res = max(res, ans);
            }
            ans += (nums[i] - nums[i - k]);
            if (mmp[nums[i - k]] > 1) {
                use--;
            }
            mmp[nums[i - k]] -= 1;
            if (mmp[nums[i]]) {
                use++;
            }
            mmp[nums[i]] += 1;
        }
        if (!use) {
            res = max(res, ans);
        }
        return res;
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long res = 0, ans = 0, use = 0;
        map<int, int> mmp;
        for (int i = 0; i < k; i++) {
            ans += nums[i];
            if (mmp[nums[i]]) {
                use += 1;
            }
            mmp[nums[i]] += 1;
        }
        for (int i = k; i < nums.size(); i++) {
            if (use <= (k - m)) {
                res = max(res, ans);
            }
            ans += (-nums[i - k] + nums[i]);
            if (mmp[nums[i]]) {
                use++;
            }
            mmp[nums[i]] += 1;
            if (mmp[nums[i - k]] > 1) {
                use--;
            }
            mmp[nums[i - k]] -= 1;
        }
        if (use <= (k - m)) {
            res = max(res, ans);
        }
        return res;
    }
};
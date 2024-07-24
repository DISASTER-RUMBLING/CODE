#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long l = 0, ans = k, res = 1;
        for (long long r = 1; r < nums.size(); r++) {
            ans -= ((nums[r] - nums[r - 1]) * (r - l));
            while (ans < 0 && l < r) {
                ans += (nums[r] - nums[l]);
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }

};
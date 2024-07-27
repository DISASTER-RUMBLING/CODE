#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0, l = 0, ans = 0, sz = nums.size();
        for (long long r = 0; r < sz; r++) {
            ans += nums[r];
            while ((ans * (r - l + 1)) >= k) {
                ans -= nums[l];
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }
};
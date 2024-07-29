#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0, sz = nums.size(), l = sz, r = sz;
        sort(nums.begin(), nums.end());
        for (long long i = 0; i < sz; i++) {
            while (l && nums[l - 1] + nums[i] >= lower) {
                l--;
            }
            while (r && nums[r - 1] + nums[i] > upper) {
                r--;
            }
            res += (min(r, i) - min(l, i));
        }
        return res;
    }
};
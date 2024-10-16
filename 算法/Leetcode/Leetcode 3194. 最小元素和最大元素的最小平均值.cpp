#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double res = 1e9;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            res = min(res, (nums[l] + nums[r]) / 2.0);
            l++;
            r--;
        }
        return res;
    }
};
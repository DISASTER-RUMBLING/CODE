#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        int sz = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) {
            res++;
        }
        for (int i = 1; i < sz; i++) {
            if (nums[i - 1] < i && i < nums[i]) {
                res++;
            }
        }
        return res + 1;
    }
};
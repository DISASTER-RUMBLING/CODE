#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sz = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> mmp;
        for (int r = 0; r < sz; r++) {
            mmp[sum] += 1;
            sum += nums[r];
            res += mmp[sum - goal];
        }
        return res;
    }
};
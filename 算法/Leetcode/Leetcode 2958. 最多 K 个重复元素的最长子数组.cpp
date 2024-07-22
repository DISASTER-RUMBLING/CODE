#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, res = 0, sz = nums.size();
        map<int, int> mmp;
        for (int r = 0; r < sz; r++) {
            mmp[nums[r]] += 1;
            if ((mmp[nums[r]]) > k) {
                while (mmp[nums[r]] > k) {
                    mmp[nums[l]] -= 1;
                    l++;
                }
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
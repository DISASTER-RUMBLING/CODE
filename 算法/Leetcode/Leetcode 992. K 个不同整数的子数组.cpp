#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

    int sum(vector<int>& nums, int k) {
        int l = 0, res = 0, sz = nums.size();
        unordered_map<int, int> mmp;
        for (int r = 0; r < sz; r++) {
            mmp[nums[r]] += 1;
            while (mmp.size() > k) {
                mmp[nums[l]] -= 1;
                if (0 == mmp[nums[l]]) {
                    mmp.erase(nums[l]);
                }
                l++;
            }
            res += (r - l);
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sum(nums, k) - sum(nums, k - 1);
    }
};
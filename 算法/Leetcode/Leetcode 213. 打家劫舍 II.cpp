#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    int Res(vector<int>& nums, int beg, int ed) {
        if (ed - beg == 0) {
            return nums[ed];
        }
        if (ed - beg == 1) {
            return max(nums[beg], nums[ed]);
        }
        vector<int> res(ed - beg + 1);
        res[0] = nums[beg];
        res[1] = max(res[0], nums[beg + 1]);
        for (int i = 2; i <= ed - beg; i++) {
            res[i] = max(res[i - 1], res[i - 2] + nums[beg + i]);
        }
        return res[(ed - beg)];
    }

    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) {
            return nums[0];
        }
        else if (sz == 2) {
            return max(nums[0], nums[1]);
        }
        else if (sz == 3) {
            return max(max(nums[0], nums[1]), nums[2]);
        }
        return max(nums[0] + Res(nums, 2, sz - 2), Res(nums, 1, sz - 1));
    }

};
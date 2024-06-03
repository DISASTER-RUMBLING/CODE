#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return abs(nums[0] - k);
        }
        int res = 9999999999;
        for (int i = 0; i < nums.size(); i++) {
            res = min(res, abs(nums[i] - k));
            for (int j = i - 1; j >= 0; j--) {
                if ((nums[j] & nums[i]) == nums[j]) {
                    break;
                }
                nums[j] &= nums[i];
                res = min(res, abs(nums[j] - k));
            }
        }
        return res;
    }
};
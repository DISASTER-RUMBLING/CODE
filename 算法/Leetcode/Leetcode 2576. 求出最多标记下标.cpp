#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size(), res = 0, l = 0;
        for (int r = (1 + sz) / 2; r < sz; r++) {
            if (nums[l] * 2 <= nums[r]) {
                l++;
                res += 2;
            }
        }
        return res;
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int sz = nums.size(), l = 0, r = 0, now = 0, num = 0;
        if (k == 1) {
            return nums;
        }
        vector<int> res(sz - k + 1, -1);
        for (r = 1; r < k; r++) {
            if (nums[r - 1] + 1 != nums[r]) {
                now++;
            }
        }
        if (now == 0) {
            res[num++] = nums[k - 1];
        }
        while (r < sz) {
            if (nums[l] + 1 != nums[l + 1]) {
                now--;
            }
            l++;
            if (r < sz && nums[r - 1] + 1 != nums[r]) {
                now++;
            }
            r++;
            if (now == 0) {
                res[l] = nums[r - 1];
            }
        }
        return res;
    }

};
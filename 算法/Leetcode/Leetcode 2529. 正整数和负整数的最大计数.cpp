#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int sz = nums.size(), l = -1, r = sz;
        if (sz == 1) {
            return nums[0] == 0 ? 0 : 1;
        }
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < 0) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        while (nums[r] == 0) {
            r++;
        }
        return max((int)(l + 1), (int)(sz - r));
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0) {
            return res;
        }
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (r < nums.size() && nums[r] == target) {
            res[0] = r;
        }
        else {
            res[0] = res[1] = -1;
            return res;
        }
        l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        res[1] = l;
        return res;
    }
};
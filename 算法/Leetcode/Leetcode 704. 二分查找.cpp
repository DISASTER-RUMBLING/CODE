#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        if (r == 1) {
            return nums[0] == target ? 0 : -1;
        }
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (nums[r] == target) {
            return r;
        }
        return -1;
    }
};
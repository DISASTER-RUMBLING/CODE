#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - 1; j++) {
                if (nums[j] > nums[j + 1] && __builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                return false;
            }
        }
        return true;
    }
};
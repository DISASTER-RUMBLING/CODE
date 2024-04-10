#define _CRT_SECURE_NO_WARNINGS
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, now;
        while (left <= right) {
            now = (left + right) >> 1;
            if (nums[now] == target) {
                return now;
            }
            else if (nums[now] < target) {
                left = now + 1;
            }
            else {
                right = now - 1;
            }
        }
        return left;
    }
};
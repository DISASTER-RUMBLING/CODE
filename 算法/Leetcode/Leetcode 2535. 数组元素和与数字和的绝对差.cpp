#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1 = 0, sum2 = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            sum1 += nums[i];
            while (nums[i]) {
                sum2 += (nums[i] % 10);
                nums[i] = nums[i] / 10;
            }
        }
        return sum1 - sum2;
    }
};
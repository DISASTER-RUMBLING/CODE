#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if (nums.size() == 2) {
            return 2;
        }
        int res = 1, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] %= 2;
            if (nums[i] == 1) {
                ans++;
            }
        }
        int flag = nums[0], fflag = 1 - nums[0];
        int fg = 1, ffg = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (flag + nums[i] == 1) {
                flag = 1 - flag;
                fg++;
            }
            if (fflag + nums[i] == 1) {
                fflag = 1 - flag;
                ffg++;
            }
        }
        return max((int)max(fg, ffg), (int)max(ans, (int)(nums.size() - ans)));
    }
};
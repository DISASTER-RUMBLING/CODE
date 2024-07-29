#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int x = 0, y = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 10) {
                x += nums[i];
            }
            else {
                y += nums[i];
            }
        }
        return x == y ? false : true;
    }
};
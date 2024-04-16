#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = (nums.size() + 1) * nums.size() / 2;
        for (auto x : nums) {
            num -= x;
        }
        return num;
    }
};
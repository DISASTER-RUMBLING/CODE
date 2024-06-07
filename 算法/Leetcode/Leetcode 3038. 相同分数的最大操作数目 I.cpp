#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int res = 1;
        int sum = nums[0] + nums[1];
        for (int i = 2; i < nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] != sum) {
                break;
            }
            res++;
        }
        return res;
    }
};
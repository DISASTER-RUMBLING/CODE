#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        long long res = 0;
        for (long long l = 0; l < nums.size(); l++) {
            for (long long r = l; r < nums.size(); r++) {
                long long last = 0, nexts;
                bool flag = 1;
                for (long long i = 0; i < nums.size(); i++) {
                    if (i == l) {
                        i = r;
                        continue;
                    }
                    if (last >= nums[i]) {
                        flag = 0;
                        nexts = i;
                        break;
                    }
                    last = nums[i];
                }
                if (flag) {
                    res++;
                }
            }
        }
        return res;
    }
};
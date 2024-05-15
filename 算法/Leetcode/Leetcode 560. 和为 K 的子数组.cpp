#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        int sz = nums.size(), res = 0;
        vector<int> sum(sz + 1, 0);
        for (int i = 0; i < sz; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j <= sz; j++) {
                if (sum[j] - sum[i] == k) {
                    res++;
                }
            }
        }
        return res;
    }

};
#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n_sz = nums.size(), d_sz = divisors.size(), res = 0, now = 0;
        sort(divisors.begin(), divisors.end());
        for (int i = 0; i < d_sz; i++) {
            int num = 0;
            for (int j = 0; j < n_sz; j++) {
                if (nums[j] % divisors[i] != 0) {
                    continue;
                }
                num++;
            }
            if (num > now) {
                res = divisors[i];
                now = num;
            }
        }
        if (now == 0) {
            return divisors[0];
        }
        return res;
    }
};
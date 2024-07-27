#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long l = 0, res = 0, num = -1, sz = nums.size(), times = 0;
        for (long long i = 0; i < sz; i++) {
            if (nums[i] > num) {
                num = nums[i];
            }
        }
        for (int r = 0; r < sz; r++) {
            if (nums[r] == num) {
                times++;
            }
            while (times >= k) {
                res += (sz - r);
                if (nums[l] == num) {
                    times--;
                }
                l++;
            }
        }
        return res;
    }
};
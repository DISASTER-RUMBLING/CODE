#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    long long sum(vector<int>& nums, long long num) {
        long long res = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            res += ((nums[i] - 1) / num) + 1;
        }
        return res;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        long long sz = nums.size(), r = 0;
        for (int i = 0; i < sz; i++) {
            r = max(r, (long long)nums[i]);
        }
        long long l = 0;
        while (l + 1 < r) {
            long long mid = (l + r) / 2;
            if (sum(nums, mid) <= threshold) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};
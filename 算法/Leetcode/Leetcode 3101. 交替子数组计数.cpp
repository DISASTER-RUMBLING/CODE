#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 0;
        long long l = 0;
        while (l < nums.size()) {
            long long r = l + 1;
            while (r < nums.size() && nums[r] != nums[r - 1]) {
                r++;
            }
            res += ((r - l) * (1 + r - l)) / 2;
            l = r;
        }
        return res;
    }
};
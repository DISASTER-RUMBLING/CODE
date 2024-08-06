#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int now = 1, mx = 0, sz = nums.size();
        for (int i = 1; i < sz; i++) {
            if (nums[i] == nums[i - 1]) {
                now++;
            }
            else {
                mx = max(now, mx);
                now = 1;
            }
        }
        mx = max(now, mx);
        return max(mx * 2 - sz, sz % 2);
    }
};
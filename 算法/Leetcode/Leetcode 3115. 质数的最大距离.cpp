#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        map<int, int> mmp;
        mmp[1] = 1;
        for (int i = 2; i <= 100; i++) {
            if (mmp[i]) {
                continue;
            }
            for (int j = i * 2; j <= 100; j += i) {
                mmp[j] = 1;
            }
        }
        int mi = -1, mx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (!mmp[nums[i]]) {
                mi = mi == -1 ? i : mi;
                mx = max(i, mx);
            }
        }
        return mx - mi;
    }
};
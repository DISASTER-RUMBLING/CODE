#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mmp;
        vector<int> use;
        for (int i = 0; i < nums.size(); i++) {
            if (mmp[nums[i]] == 0) {
                use.push_back(nums[i]);
            }
            mmp[nums[i]] += nums[i];
        }
        if (use.size() == 1) {
            return mmp[use[0]];
        }
        sort(use.begin(), use.end());
        for (int i = use[0] + 1; i <= use[use.size() - 1]; i++) {
            mmp[i] = max(mmp[i - 1], mmp[i - 2] + mmp[i]);
        }
        return mmp[use[use.size() - 1]];
    }

};
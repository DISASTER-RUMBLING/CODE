#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (k == 1 || nums.size() == 1) {
            return nums;
        }
        if (k == nums.size()) {
            sort(nums.begin(), nums.end());
            res.push_back(nums[nums.size() - 1]);
            return res;
        }
        map<int, int> mmp;
        for (int i = 0; i < k; i++) {
            mmp[nums[i]]++;
        }
        res.push_back(mmp.rbegin()->first);
        for (int i = 1; i < nums.size() - k + 1; i++) {
            mmp[nums[i + k - 1]]++;
            if (mmp[nums[i - 1]] == 1) {
                mmp.erase(nums[i - 1]);
            }
            else {
                mmp[nums[i - 1]]--;
            }
            res.push_back(mmp.rbegin()->first);
        }
        return res;
    }
};
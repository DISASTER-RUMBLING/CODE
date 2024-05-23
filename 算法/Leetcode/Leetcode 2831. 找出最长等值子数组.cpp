#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        map<int, vector<int>> mmp;
        map<int, int> use;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (use.find(nums[i]) != use.end()) {
                mmp[nums[i]].push_back((i - use[nums[i]]) + mmp[nums[i]].back());
            }
            else {
                mmp[nums[i]].push_back(0);
            }
            use[nums[i]] = i;
        }
        for (auto x : mmp) {
            int sz = x.second.size(), left = 0, right = 0;
            while (right < sz) {
                if (x.second[right] - x.second[left] - (right - left) > k) {
                    left++;
                }
                if (x.second[right] - x.second[left] - (right - left) <= k) {
                    res = max(right - left + 1, res);
                    right++;
                }
            }
        }
        return res;
    }
};
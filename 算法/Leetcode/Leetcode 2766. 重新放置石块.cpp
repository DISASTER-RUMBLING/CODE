#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> res;
        map<int, bool> mmp;
        for (int i = 0; i < nums.size(); i++) {
            mmp[nums[i]] = 1;
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            mmp[moveFrom[i]] = 0;
            mmp[moveTo[i]] = 1;
        }
        for (auto x : mmp) {
            if (x.second) {
                res.push_back(x.first);
            }
        }
        return res;
    }
};
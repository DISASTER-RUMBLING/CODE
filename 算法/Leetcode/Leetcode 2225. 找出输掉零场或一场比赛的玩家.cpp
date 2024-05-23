#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);
        map<int, int> mmp;
        for (int i = 0; i < matches.size(); i++) {
            if (mmp[matches[i][0]] >= 0) {
                mmp[matches[i][0]] = 1;
            }
            if (mmp[matches[i][1]] >= 0) {
                mmp[matches[i][1]] = -1;
            }
            else if (mmp[matches[i][1]] < 0) {
                mmp[matches[i][1]] -= 1;
            }
        }
        for (auto x : mmp) {
            if (x.second > 0) {
                res[0].push_back(x.first);
            }
            else if (x.second == -1) {
                res[1].push_back(x.first);
            }
        }
        return res;
    }

};
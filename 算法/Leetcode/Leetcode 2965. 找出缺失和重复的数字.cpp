#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> res;
        map<int, int> mmp;
        int sz = grid[0].size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                mmp[grid[i][j]] += 1;
                if (mmp[grid[i][j]] == 2) {
                    res.push_back(grid[i][j]);
                }
            }
        }
        sz *= sz;
        for (int i = 1; i <= (sz); i++) {
            if (mmp[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
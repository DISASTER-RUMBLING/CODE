#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

class Solution {
public:

    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size());
        for (int i = 0; i < grid[0].size(); i++) {
            int mx = 1;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] < 0) {
                    mx = max(mx, (int)log10(-grid[j][i]) + 2);
                }
                else if (grid[j][i] > 0) {
                    mx = max(mx, (int)log10(grid[j][i]) + 1);
                }
            }
            res[i] = mx;
        }
        return res;
    }

};
#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int i = 0; i < grid[0].size(); i++) {
            int now = grid[0][i];
            for (int j = 0; j < grid.size(); j++) {
                if (i - 1 > 0 && grid[j][i] == grid[j][i - 1]) {
                    return false;
                }
                if (i + 1 < grid[0].size() && grid[j][i] == grid[j][i + 1]) {
                    return false;
                }
                if (now != grid[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

};
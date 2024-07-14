#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        vector<int> row(grid.size(), 0), col(grid.size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                res += (max(grid[i][j], min(row[i], col[j])) - grid[i][j]);
            }
        }
        return res;
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row = grid[0].size(), col = grid.size(), res = 0, ans = 0;
        for (int i = 0; i < (col); i++) {
            for (int j = 0; j < (row / 2); j++) {
                if (grid[i][j] != grid[i][row - j - 1]) {
                    res++;
                }
            }
        }
        for (int i = 0; i < (row); i++) {
            for (int j = 0; j < (col / 2); j++) {
                if (grid[col - j - 1][i] != grid[j][i]) {
                    ans++;
                }
            }
        }
        return min(res, ans);
    }
};
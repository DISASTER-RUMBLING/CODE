#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long res = 0, rw = grid.size(), cl = grid[0].size();
        vector<int> row(rw, 0), col(cl, 0);
        for (int i = 0; i < rw; i++) {
            for (int j = 0; j < cl; j++) {
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for (int i = 0; i < rw; i++) {
            for (int j = 0; j < cl; j++) {
                if (grid[i][j]) {
                    res += ((row[i] - 1) * (col[j] - 1));
                }
            }
        }
        return res;
    }

};
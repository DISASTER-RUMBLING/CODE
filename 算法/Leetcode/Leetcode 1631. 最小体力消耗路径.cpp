#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:

    int row, col;
    int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };

    bool Check(vector<vector<int>>& heights, int mid, int i, int j, vector<int>& arr) {
        if (i == row - 1 && j == col - 1) {
            return true;
        }
        if (arr[i * col + j]) {
            return false;
        }
        arr[i * col + j] = 1;
        for (int k = 0; k < 4; k++) {
            if ((i + dir[k][0]) < 0 || (i + dir[k][0]) == row || (j + dir[k][1]) < 0 || (j + dir[k][1]) == col) {
                continue;
            }
            if (abs(heights[i + dir[k][0]][j + dir[k][1]] - heights[i][j]) > mid) {
                continue;
            }
            if (Check(heights, mid, i + dir[k][0], j + dir[k][1], arr)) {
                arr[i * col + j] = 0;
                return true;
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = -1, r = 0;
        row = heights.size(), col = heights[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if (ni >= 0 && ni < row && nj >= 0 && nj < col) {
                        r = max(r, abs(heights[i][j] - heights[ni][nj]));
                    }
                }
            }
        }
        while (l + 1 < r) {
            vector<int> arr(row * col, 0);
            int mid = (l + r) / 2;
            if (Check(heights, mid, 0, 0, arr)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }





};
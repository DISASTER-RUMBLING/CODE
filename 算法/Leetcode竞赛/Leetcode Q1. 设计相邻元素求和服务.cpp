#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class neighborSum {
public:
    vector<pair<int, int>> arr;

    neighborSum(vector<vector<int>>& grid) {
        int row = grid[0].size(), col = grid.size();
        vector<pair<int, int>> now(row * col, { 0,0 });
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                int nums = grid[i][j];
                if (i != 0) {
                    now[grid[i - 1][j]].first += nums;
                }
                if (i != col - 1) {
                    now[grid[i + 1][j]].first += nums;
                }
                if (j != 0) {
                    now[grid[i][j - 1]].first += nums;
                }
                if (j != row - 1) {
                    now[grid[i][j + 1]].first += nums;
                }
                if (i != 0 && j != 0) {
                    now[grid[i - 1][j-1]].second += nums;
                }
                if (i != 0 && j != (row - 1)) {
                    now[grid[i - 1][j+1]].second += nums;
                }
                if (i != (col - 1) && j != 0) {
                    now[grid[i + 1][j - 1]].second += nums;
                }
                if (i != (col - 1) && j != (row - 1)) {
                    now[grid[i + 1][j + 1]].second += nums;
                }
            }
        }
    }

    int adjacentSum(int value) {
        return arr[value].first;
    }

    int diagonalSum(int value) {
        return arr[value].second;
    }
};
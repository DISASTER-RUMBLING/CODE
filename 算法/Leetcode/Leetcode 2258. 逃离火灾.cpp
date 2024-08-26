#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:


    //               ио     вС     ср    об
    int b[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
    int row, col;

    void dfs(vector<vector<int>>& arr, vector<vector<int>>& grid, int i, int j, int times) {
        if (grid[i][j] == 2 || arr[i][j] <= times) {
            return;
        }
        arr[i][j] = times;
        for (int k = 0; k < 4; k++) {
            if (i + b[k][0] == row || i + b[k][0] < 0 || j + b[k][1] == col || j + b[k][1] < 0) {
                continue;
            }
            dfs(arr, grid, i + b[k][0], j + b[k][1], times + 1);
        }
        return;
    }

    void Dfs(vector<vector<int>>& arr, vector<vector<int>>& peo, vector<vector<int>>& grid, int i, int j, int times) {
        if (grid[i][j] > 0 || peo[i][j] <= times || times >= arr[i][j]) {
            return;
        }
        peo[i][j] = times;
        for (int k = 0; k < 4; k++) {
            if (i + b[k][0] == row || i + b[k][0] < 0 || j + b[k][1] == col || j + b[k][1] < 0) {
                continue;
            }
            Dfs(arr, peo, grid, i + b[k][0], j + b[k][1], times + 1);
        }
        return;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int num = 0, nums = 0;
        row = grid.size(), col = grid[0].size();
        vector<vector<int>> arr(row, vector<int>(col, 25000)), peo(row, vector<int>(col, 25000));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    num++;
                    if ((i + 1 == row || (i + 1 < row && grid[i + 1][j] == 2)) && (i == 0 || (i > 0 && grid[i - 1][j] == 2)) && (j + 1 == col || (j + 1 < col && grid[i][j + 1] == 2)) && (j == 0 || (j > 0 && grid[i][j - 1] == 2))) {
                        nums++;
                        continue;
                    }
                    dfs(arr, grid, i, j, 0);
                }
            }
        }
        Dfs(arr, peo, grid, 0, 0, 0);
        if (num == nums && peo[row - 1][col - 1] != 25000) {
            return 1e9;
        }
        peo[row - 1][col - 1] = min(peo[row - 2][col - 1], peo[row - 1][col - 2]) + 1;
        int d = (arr[row - 1][col - 1]) - peo[row - 1][col - 1];
        if (d < 0) {
            return -1;
        }
        else if (((peo[row - 2][col - 1] != 25000 && arr[row - 2][col - 1] > d + peo[row - 2][col - 1]) || (peo[row - 1][col - 2] != 25000 && arr[row - 1][col - 2] > d + peo[row - 1][col - 2]))) {
            return d;
        }
        return d - 1;
    }



};
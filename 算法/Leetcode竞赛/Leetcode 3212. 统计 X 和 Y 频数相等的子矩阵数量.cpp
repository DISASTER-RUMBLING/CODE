#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    struct node {
        int x, y;
    };

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<node>> arr(grid.size(), vector<node>(grid[0].size()));
        int row = grid[0].size(), col = grid.size(), res = 0;
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                if (j > 0) {
                    arr[i][j].x = arr[i][j - 1].x;
                    arr[i][j].y = arr[i][j - 1].y;
                }
                if (grid[i][j] == 'X') {
                    arr[i][j].x++;
                }
                else if (grid[i][j] == 'Y') {
                    arr[i][j].y++;
                }
            }
            if (i > 0) {
                for (int j = 0; j < row; j++) {
                    arr[i][j].x += arr[i - 1][j].x;
                    arr[i][j].y += arr[i - 1][j].y;
                }
            }
            for (int j = 0; j < row; j++) {
                if (arr[i][j].x == arr[i][j].y && arr[i][j].x > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};
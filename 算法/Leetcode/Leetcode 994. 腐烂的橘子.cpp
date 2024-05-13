#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<queue>
#include<map>

using namespace std;

class Solution {
public:

    struct node {
        int x, y;
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        int org = 0;
        //第一个表示y的操作，第二个表示x的操作
        int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
        queue<node> que, nex;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    org++;
                }
                if (grid[i][j] == 2) {
                    que.push({ i,j });
                }
            }
        }
        while (!que.empty()) {
            int n = que.size();
            int flag = 0;
            for (int i = 0; i < n; i++) {
                node now = que.front();
                que.pop();
                for (int j = 0; j < 4; j++) {
                    int x = now.x + dir[j][0];
                    int y = now.y + dir[j][1];
                    if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        que.push({ x,y });
                        org--;
                        flag = 1;
                    }
                }
            }
            if (flag) {
                res++;
            }

        }
        return org == 0 ? res : -1;
    }

};
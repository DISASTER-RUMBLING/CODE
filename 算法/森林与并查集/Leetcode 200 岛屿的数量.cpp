#define _CRT_SECURE_NO_WARNINGS
#include<vector>
using namespace std;

class Unionset {
public:
    Unionset(int n) :fa(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int find(int i) {
        return fa[i] = (fa[i] == i ? i : find(fa[i]));
    }
    void merge(int x, int y) {
        if (find(x) == find(y)) {
            return;
        }
        fa[find(x)] = find(y);
        return;
    }
    vector<int> fa;
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid[0].size(), n = grid.size();
        Unionset u(m * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                int ind = (i * m) + j + 1;
                if (i + 1 < n && grid[i + 1][j] != '0') {
                    u.merge(ind, ind + m);
                }
                if (j + 1 < m && grid[i][j + 1] != '0') {
                    u.merge(ind, ind + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ind = (i * m) + j + 1;
                if (grid[i][j] == '1' && u.find(ind) == ind) {
                    res++;
                }
            }
        }
        return res;
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<vector>
using namespace std;

class Union {
public:
    Union(int n) :fa(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int find(int i) {
        return fa[i] = (fa[i] == i ? i : find(fa[i]));
    }
    void merge(int i, int j) {
        if (find(i) == find(j)) {
            return;
        }
        fa[find(i)] = find(j);
        return;
    }
    vector<int> fa;
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        Union u(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'O') {
                    continue;
                }
                int ind = (i * n) + j + 1;
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    u.merge(ind, 0);
                }
                if (i + 1 < m && board[i + 1][j] == 'O') {
                    u.merge(ind, ind + n);
                }
                if (j + 1 < n && board[i][j + 1] == 'O') {
                    u.merge(ind, ind + 1);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'O') {
                    continue;
                }
                int ind = (i * n) + j + 1;
                if (u.find(ind) != u.find(0)) {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
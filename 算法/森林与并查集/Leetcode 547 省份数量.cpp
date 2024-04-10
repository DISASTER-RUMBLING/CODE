#define _CRT_SECURE_NO_WARNINGS
#include<vector>
using namespace std;

class Unionset {
public:
    Unionset(int n) :fa(n + 1) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int n) {
        return fa[n] = (fa[n] == n ? n : find(fa[n]));
    }
    void merge(int x, int y) {
        fa[find(x)] = find(y);
        return;
    }
    vector<int> fa;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Unionset u(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] && i != j) {
                    u.merge(i, j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (u.find(i) == i) {
                res++;
            }
        }
        return res;
    }
};
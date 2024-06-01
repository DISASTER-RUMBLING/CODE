#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Solution {
public:

    int dfs(int now, int limit, int pos, int n) {
        if (pos == n && now == 0) {
            return 1;
        }
        else if (pos == n && now != 0) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i <= min(limit, now); i++) {
            res += dfs(now - i, limit, pos + 1, n);
        }
        return res;
    }

    int distributeCandies(int n, int limit) {
        return dfs(n, limit, 0, 3);
    }
};
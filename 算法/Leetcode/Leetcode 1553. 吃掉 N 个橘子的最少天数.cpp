#define _CRT_SECURE_NO_WARNINGS
#include<map>
using namespace std;

class Solution {
public:

    map<int, int> res;

    void dfs(int now) {
        if (res[now] != 0) {
            return;
        }
        else if (now == 0) {
            return;
        }
        if (res[now / 2] == 0) {
            dfs(now / 2);
        }
        if (res[now / 3] == 0) {
            dfs(now / 3);
        }
        res[now] = min(res[now / 3] + now % 3, res[now / 2] + now % 2) + 1;
    }

    int minDays(int n) {
        res[0] = 0;
        res[1] = 1;
        dfs(n);
        return res[n];
    }

};
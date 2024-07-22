#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& bombs, vector<bool>& use, int now, int& sum) {
        int sz = bombs.size();
        use[now] = 1;
        for (int i = 0; i < sz; i++) {
            if (!use[i]) {
                long long nw = pow(abs(bombs[i][0] - bombs[now][0]), 2) + pow(abs(bombs[i][1] - bombs[now][1]), 2);
                long long mr = pow(bombs[now][2], 2);
                if (nw <= mr) {
                    dfs(bombs, use, i, sum);
                }
            }
        }
        sum += 1;
        return;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int sz = bombs.size(), res = 1;
        vector<int> arr(sz, 0);
        for (int i = 0; i < sz; i++) {
            vector<bool> use(sz, 0);
            use[i] = 1;
            int ans = 0;
            dfs(bombs, use, i, ans);
            res = max(res, ans);
        }
        return res;
    }

};
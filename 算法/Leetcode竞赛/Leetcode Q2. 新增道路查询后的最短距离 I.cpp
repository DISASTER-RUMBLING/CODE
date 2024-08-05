#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> now(n);
        //A->B
        //mmp1是记录哪些A能到B，mmp2是记录A能到哪些B
        map<int, vector<int>> mmp1, mmp2;
        for (int i = n - 1; i > 0; i--) {
            mmp1[i].push_back(i - 1);
            now[i] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            mmp2[i].push_back(i + 1);
        }
        now[0] = 0;
        int sz = queries.size();
        vector<int> res(sz, n);
        for (int i = 0; i < sz; i++) {
            mmp1[queries[i][1]].push_back(queries[i][0]);
            mmp2[queries[i][0]].push_back(queries[i][1]);
            now[queries[i][1]] = min(now[queries[i][1]], now[queries[i][0]] + 1);
            for (int j = queries[i][1] + 1; j < n; j++) {
                for (int k = 0; k < mmp1[j].size(); k++) {
                    now[j] = min(now[j], now[mmp1[j][k]] + 1);
                }
            }
            res[i] = now[n - 1];
        }
        return res;
    }
};
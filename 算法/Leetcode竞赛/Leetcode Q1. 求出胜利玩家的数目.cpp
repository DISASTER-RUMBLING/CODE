#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int res = 0, sz = pick.size();
        map<int, map<int, int>> mmp;
        map<int, bool> use;
        for (int i = 0; i < sz; i++) {
            mmp[pick[i][0]][pick[i][1]] += 1;
            if (mmp[pick[i][0]][pick[i][1]] > pick[i][0] && !use[pick[i][0]]) {
                res++;
                use[pick[i][0]] = 1;
            }
        }
        return res;
    }
};
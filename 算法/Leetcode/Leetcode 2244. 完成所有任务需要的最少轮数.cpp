#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<vector>

using namespace std;

class Solution {
public:

    int minimumRounds(vector<int>& tasks) {
        int ans = 0, mx = 0;
        map<int, int> mmp, res;
        int sz = tasks.size();
        for (int i = 0; i < sz; i++) {
            mmp[tasks[i]] += 1;
            mx = max(mx, mmp[tasks[i]]);
        }
        res[2] = 1;
        res[3] = 1;
        res[4] = 2;
        for (int i = 5; i <= mx; i++) {
            res[i] = 1 + min(res[i - 2], res[i - 3]);
        }
        for (auto x : mmp) {
            if (x.second == 1) {
                return -1;
            }
            else {
                ans += res[x.second];
            }
        }
        return ans;
    }

};
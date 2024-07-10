#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void dfs(vector<string>& res, int now, int n, string ans) {
        if (ans.size() == n) {
            res.push_back(ans);
            return;
        }
        if (ans.back() == '0') {
            dfs(res, now + 1, n, ans + '1');
        }
        else if (ans.back() == '1') {
            dfs(res, now + 1, n, ans + '0');
            dfs(res, now + 1, n, ans + '1');
        }
        return;
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        dfs(res, 0, n, "1");
        dfs(res, 0, n, "0");
        return res;
    }
};
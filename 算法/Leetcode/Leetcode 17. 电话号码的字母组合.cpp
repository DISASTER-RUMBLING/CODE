#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>

using namespace std;

class Solution {
public:

    void dfs(vector<string> uses, vector<string>& res, string digits, int now, string nw) {
        if (now == digits.size()) {
            res.push_back(nw);
            return;
        }
        for (int i = 0; i < uses[(int)(digits[now] - '0')].size(); i++) {
            dfs(uses, res, digits, now + 1, nw + uses[(int)(digits[now] - '0')][i]);
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res, uses(10);
        if (digits.size() == 0) {
            return res;
        }
        uses[2] = "abc";
        uses[3] = "def";
        uses[4] = "ghi";
        uses[5] = "jkl";
        uses[6] = "mno";
        uses[7] = "pqrs";
        uses[8] = "tuv";
        uses[9] = "wxyz";
        dfs(uses, res, digits, 0, "");
        return res;
    }
};
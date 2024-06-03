#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> arr(26);
        map<int, int> mmp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                arr[(int)(s[i] - 'a')].push(i);
                continue;
            }
            int pos, flag = 0;
            for (int j = 0; j < 26; j++) {
                if (!arr[j].empty()) {
                    pos = arr[j].top();
                    arr[j].pop();
                    flag = 1;
                    break;
                }
            }
            mmp[i] = 1;
            if (flag) {
                mmp[pos] = 1;
            }
        }
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (!mmp[i]) {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
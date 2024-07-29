#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:

    int calPoints(vector<string>& operations) {
        int res = 0, sz = operations.size();
        stack<int> sta;
        for (int i = 0; i < sz; i++) {
            if (operations[i] == "+") {
                int num = sta.top();
                sta.pop();
                int y = num + sta.top();
                sta.push(num);
                sta.push(y);
            }
            else if (operations[i] == "D") {
                sta.push(sta.top() * 2);
            }
            else if (operations[i] == "C") {
                sta.pop();
                continue;
            }
            else {
                int num = 0, falg = 1;
                for (int j = 0; j < operations[i].size(); j++) {
                    if (operations[i][j] == '-') {
                        falg = -1;
                        continue;
                    }
                    num = num * 10 + (operations[i][j] - '0');
                }
                sta.push(num * falg);
            }
        }
        while (!sta.empty()) {
            res += sta.top();
            sta.pop();
        }
        return res;
    }

};
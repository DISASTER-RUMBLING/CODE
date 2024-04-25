#define _CRT_SECURE_NO_WARNINGS
#include<stack>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int sz = tokens.size();
        stack<int> sta;
        for (int i = 0; i < sz; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int x = sta.top();
                sta.pop();
                int y = sta.top();
                sta.pop();
                if (tokens[i] == "+") {
                    sta.push(x + y);
                }
                else if (tokens[i] == "-") {
                    sta.push(y - x);
                }
                else if (tokens[i] == "*") {
                    sta.push(x * y);
                }
                else if (tokens[i] == "/") {
                    sta.push(y / x);
                }
            }
            else {
                int siz = tokens[i].size();
                int j = 0, flag = 0;
                int res = 0;
                if (tokens[i][0] == '-') {
                    flag = 1;
                    j++;
                }
                for (j; j < siz; j++) {
                    res = res * 10 + (tokens[i][j] - '0');
                }
                if (flag) {
                    res *= -1;
                }
                sta.push(res);
            }
        }
        return sta.top();
    }
};
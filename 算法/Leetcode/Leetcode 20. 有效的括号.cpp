#define _CRT_SECURE_NO_WARNINGS
#include<stack>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sta.push(s[i]);
            }
            if (s[i] == ')') {
                if (!sta.empty() && sta.top() == '(') {
                    sta.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == ']') {
                if (!sta.empty() && sta.top() == '[') {
                    sta.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == '}') {
                if (!sta.empty() && sta.top() == '{') {
                    sta.pop();
                }
                else {
                    return false;
                }
            }
        }
        return sta.empty();
    }
};
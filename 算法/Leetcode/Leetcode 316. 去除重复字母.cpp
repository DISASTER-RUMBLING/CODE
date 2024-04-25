#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> mmp;
        map<char, bool> ans;
        for (int i = 0; i < s.size(); i++) {
            mmp[s[i]]++;
        }
        string res;
        for (int i = 0; i < s.size(); i++) {
            mmp[s[i]]--;
            if (ans[s[i]]) {
                continue;
            }
            while (!res.empty() && s[i] < res.back() && mmp[res.back()]) {
                ans[res.back()] = false;
                res.pop_back();
            }
            res += s[i];
            ans[s[i]] = 1;
        }
        return res;
    }
};
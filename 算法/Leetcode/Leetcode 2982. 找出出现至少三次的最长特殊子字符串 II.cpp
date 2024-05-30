#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int res = -1;
        int sz = s.size();
        map<char, vector<int>> mmp;
        int lon = 0;
        for (int i = 0; i < sz; i++) {
            lon++;
            if (s[i] != s[i + 1] || i == sz - 1) {
                mmp[s[i]].push_back(lon);
                lon = 0;
            }
        }
        for (auto x : mmp) {
            x.second.push_back(0);
            x.second.push_back(0);
            sort(x.second.begin(), x.second.end());
            sz = x.second.size();
            res = max(res, max(x.second[sz - 1] - 2, max(x.second[sz - 3], min(x.second[sz - 1] - 1, x.second[sz - 2]))));
        }
        return res == 0 ? -1 : res;
    }
};
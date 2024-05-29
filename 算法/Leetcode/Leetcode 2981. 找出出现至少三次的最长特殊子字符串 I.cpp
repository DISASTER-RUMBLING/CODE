#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<string>

using namespace std;

int maximumLength(string s) {
    map<string, int> mmp;
    int res = -1;
    for (int i = 0; i < s.size(); i++) {
        string h;
        h = s[i];
        mmp[h] += 1;
        int j = 1;
        while ((i+j)<s.size() && s[i + j] == s[i]) {
            h += s[i + (j++)];
            mmp[h] += 1;
        }
    }
    for (auto x : mmp) {
        if (x.second >= 3) {
            res = max((int)x.first.size(), res);
        }
    }
    return res;
}
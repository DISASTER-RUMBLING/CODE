#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        map<char, int> mmp1, mmp2;
        int sz1 = s.size(), sz2 = p.size();
        if (sz1 < sz2) {
            return res;
        }
        for (int i = 0; i < sz2; i++) {
            mmp1[s[i]] += 1;
            mmp2[p[i]] += 1;
        }
        for (int i = sz2; i < sz1; i++) {
            int flag = 1;
            for (auto x : mmp2) {
                if (mmp1[x.first] != x.second) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                res.push_back(i - sz2);
            }
            mmp1[s[i]] += 1;
            mmp1[s[i - sz2]] -= 1;
        }
        int flag = 1;
        for (auto x : mmp2) {
            if (mmp1[x.first] != x.second) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            res.push_back(sz1 - sz2);
        }
        return res;
    }
};
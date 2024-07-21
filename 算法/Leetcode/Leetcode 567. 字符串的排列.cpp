#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        map<char, int> mmp1, mmp2;
        int sz1 = s1.size(), sz2 = s2.size();
        for (int i = 0; i < sz1; i++) {
            mmp1[s1[i]] += 1;
            mmp2[s2[i]] += 1;
        }
        for (int i = sz1; i < sz2; i++) {
            int flag = 1;
            for (int j = 0; j < sz1; j++) {
                if (mmp1[s1[j]] != mmp2[s1[j]]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                return true;
            }
            mmp2[s2[i - sz1]] -= 1;
            mmp2[s2[i]] += 1;
        }
        int flag = 1;
        for (int j = 0; j < sz1; j++) {
            if (mmp1[s1[j]] != mmp2[s1[j]]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return true;
        }
        return false;
    }
};
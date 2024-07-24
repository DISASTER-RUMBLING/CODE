#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int sz = s.size(), tar = sz / 4;
        map<char, int> mmp;
        for (int i = 0; i < sz; i++) {
            mmp[s[i]] += 1;
        }
        if (mmp['Q'] == mmp['W'] && mmp['W'] == mmp['E'] && mmp['E'] == mmp['R'] && mmp['R'] == tar) {
            return 0;
        }
        int l = 0, res = sz + 1;
        for (int r = 0; r < sz; r++) {
            mmp[s[r]]--;
            while (mmp['Q'] <= tar && mmp['W'] <= tar && mmp['R'] <= tar && mmp['E'] <= tar) {
                res = min(res, r - l + 1);
                mmp[s[l]]++;
                l++;
            }
        }
        return res;
    }
};
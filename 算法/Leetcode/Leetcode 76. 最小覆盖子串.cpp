#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<map>

using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {
        int tsz = t.size(), ssz = s.size(), l = 0, resl = 0, resr = ssz;
        if (tsz > ssz) {
            return "";
        }
        else if (tsz == ssz && !(t.compare(s))) {
            return s;
        }
        map<char, int> tar;
        for (int i = 0; i < tsz; i++) {
            tar[t[i]] += 1;
        }
        for (int r = 0; r < ssz; r++) {
            tar[(s[r])] -= 1;
            int flag = 1;
            for (auto x : tar) {
                if (x.second > 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                while ((tar[s[l]] + 1) <= 0) {
                    tar[s[l]] += 1;
                    l++;
                }
                if ((resr - resl) > (r - l)) {
                    resr = r;
                    resl = l;
                }
            }
        }
        int flag = 1;
        for (int i = 0; i < tsz; i++) {
            if (tar[t[i]] > 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return s.substr(resl, resr - resl + 1);
        }
        else {
            return "";
        }
    }

};
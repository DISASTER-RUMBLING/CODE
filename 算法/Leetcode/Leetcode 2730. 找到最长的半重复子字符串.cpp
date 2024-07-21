#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        if (s.size() <= 2) {
            return s.size();
        }
        int l = 0, r = 0, same = 0, res = 0;
        for (r = 1; r < s.size(); r++) {
            if (s[r] == s[r - 1]) {
                same++;
                if (same > 1) {
                    for (l++; s[l] != s[l - 1]; l++);
                }
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
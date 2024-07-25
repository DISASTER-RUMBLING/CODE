#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int sz = s.size(), res = 0, l = 0, use[3] = { 0,0,0 };
        for (int r = 0; r < sz; r++) {
            use[(int)(s[r] - 'a')] += 1;
            while (use[0] > 0 && use[1] > 0 && use[2] > 0) {
                res += (sz - r);
                use[(int)(s[l++] - 'a')] -= 1;
            }
        }
        return res;
    }
};
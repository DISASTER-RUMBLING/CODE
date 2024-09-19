#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 0, sz = s.size();
        for (int i = 0; i < sz; i++) {
            int num = 1;
            while (num + i < sz && (s[i + num]) == (char)(s[i + num - 1] + 1)) {
                num++;
            }
            res = max(res, num);
        }
        return res;
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '1') {
                res += ans;
                continue;
            }
            ans++;
        }
        return res;
    }
};
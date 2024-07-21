#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ans++;
            }
        }
        return ans ? true : false;
    }
};
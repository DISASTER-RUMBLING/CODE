#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int sz = s.size(), l = 0, a = 0;
        for (int i = 0; i < sz; i++) {
            if (s[i] == 'A') {
                a++;
                l = 0;
                if (a >= 2) {
                    return false;
                }
            }
            else if (s[i] == 'L') {
                l++;
                if (l >= 3) {
                    return false;
                }
            }
            else {
                l = 0;
            }
        }
        return true;
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            if ((s[i] - '0') % 2 == (s[i + 1] - '0') % 2 && s[i] > s[i + 1]) {
                swap(s[i], s[i + 1]);
                return s;
            }
        }
        return s;
    }
};
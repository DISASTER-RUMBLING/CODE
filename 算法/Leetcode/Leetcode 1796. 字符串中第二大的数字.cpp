#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int last = -1, now = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' > now && s[i] >= '0' && s[i] <= '9') {
                last = now;
                now = s[i] - '0';
            }
            else if (now != (s[i] - '0') && s[i] - '0' > last && s[i] >= '0' && s[i] <= '9') {
                last = s[i] - '0';
            }
        }
        return last;
    }
};
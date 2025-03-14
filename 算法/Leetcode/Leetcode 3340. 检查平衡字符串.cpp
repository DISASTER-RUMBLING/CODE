#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int single = 0, dou = 0, sz = num.size();
        for (int i = 0; i < sz; i++) {
            i % 2 ? single += (int)(num[i] - '0') : dou += (int)(num[i] - '0');
        }
        return single == dou;
    }
};
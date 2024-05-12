#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<iostream>

using namespace std;

int findPermutationDifference(string s, string t) {
    map<char, int> mmp1, mmp2;
    for (int i = 0; i < s.size(); i++) {
        mmp1[s[i]] = i;
        mmp2[t[i]] = i;
    }
    int res = 0;
    for (char i = 'a'; i <= 'z'; i++) {
        res += abs(mmp1[i] - mmp2[i]);
    }
    return res;
}
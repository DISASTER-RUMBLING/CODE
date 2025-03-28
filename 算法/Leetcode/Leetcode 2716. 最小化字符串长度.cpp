#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Solution {
public:
	int minimizedStringLength(string s) {
		int use[26] = { 0 }, sz = s.size(), res = 0;
		for (int i = 0; i < sz; i++) {
			use[(int)(s[i] - 'a')]++;
			if (use[(int)(s[i] - 'a')] == 1) {
				res++;
			}
		}
		return res;
	}
};
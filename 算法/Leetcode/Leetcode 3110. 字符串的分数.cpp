#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>

using namespace std;

int scoreOfString(string s) {
	int res = 0, sz = s.size();
	for (int i = 1; i < sz; i++) {
		res += abs((int)(s[i - 1] - s[i]));
	}
	return res;
}
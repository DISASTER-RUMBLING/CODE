#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Solution {
public:
	int minimumSum(int n, int k) {
		int res = 0;
		for (int i = 1, j = k / 2; i <= j && n; n--, i++) {
			res += i;
		}
		for (int i = k; n; n--, i++) {
			res += i;
		}
		return res;
	}
};
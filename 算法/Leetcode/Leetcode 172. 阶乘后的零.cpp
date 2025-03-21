#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

	int trailingZeroes(int n) {
		int p = 5, res = 0;
		while (p <= n) {
			res += (n / p);
			p *= 5;
		}
		return res;
	}

};
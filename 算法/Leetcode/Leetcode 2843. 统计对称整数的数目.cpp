#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Solution {
public:

	int Check(int num) {
		int res = 0;
		while (num) {
			res += 1;
			num /= 10;
		}
		return res;
	}

	int countSymmetricIntegers(int low, int high) {
		int res = 0;
		for (int i = low; i <= high; i++) {
			int num = Check(i);
			if (!(num % 2)) {
				int l = 0, r = 0;
				int num1 = i;
				for (int j = 0; j < num / 2; j++) {
					l += (num1 % 10);
					num1 /= 10;
				}
				for (int j = 0; j < num / 2; j++) {
					r += (num1 % 10);
					num1 /= 10;
				}
				if (l == r) {
					res++;
				}
			}
		}
		return res;
	}

};
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int res = 0;

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int main() {

	for (int i = 1; i <= 2020; i++) {
		for (int j = 1; j <= 2020; j++) {
			if (gcd(i, j) == 1) {
				res++;
			}
		}
	}
	printf("%d", res);

	return 0;
}
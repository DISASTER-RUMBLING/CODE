#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int res = 0;

int main() {

	for (int i = 1; i <= 2020; i++) {
		int x = i;
		while (x) {
			if (x % 10 == 2) {
				res++;
			}
			x /= 10;
		}
	}
	printf("%d", res);

	return 0;
}
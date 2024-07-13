#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	int times;
	scanf("%d", &times);
	while (times--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int n = 5;
		while (n--) {
			a >= b ? (b >= c ? c++ : b++) : (a >= c ? c++ : a++);
		}
		printf("%d\n", a * b * c);
	}

	return 0;
}
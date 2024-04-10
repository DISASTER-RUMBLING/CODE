#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int n, times = 0;
int num[1200] = { 6,2,5,5,4,5,6,3,7,6 };

int Check(int n) {
	int sum = 0, now = n;
	while (now) {
		sum += num[now % 10];
		now /= 10;
	}
	return sum;
}

int main() {

	scanf("%d", &n);
	for (int i = 10; i <= 99; i++) {
		num[i] = Check(i);
	}
	for (int i = 100; i <= 999; i++) {
		num[i] = Check(i);
	}
	for (int i = 1000; i <= 1111; i++) {
		num[i] = Check(i);
	}
	for (int i = 0, c; i < 1111; i++) {
		for (int j = 0; j < 1111; j++) {
			c = i + j;
			if ((num[i]+num[j]+Check(c)) == (n - 4)) {
				times++;
			}
		}
	}
	printf("%d", times);

	return 0;
}
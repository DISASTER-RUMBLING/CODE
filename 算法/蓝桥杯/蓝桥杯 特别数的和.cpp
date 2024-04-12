#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int n;
long long sum = 0;

bool check(int num) {
	while (num) {
		if (num % 10 == 2 || num % 10 == 0 || num % 10 == 1 || num % 10 == 9) {
			return true;
		}
		num /= 10;
	}
	return false;
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n;i++) {
		if (check(i)) {
			sum += i;
		}
	}
	printf("%lld", sum);

	return 0;
}
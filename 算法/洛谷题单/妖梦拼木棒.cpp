#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int n, times = 0, num[5005] = { 0 }, Max = 0, Min = 99999;
const int mod = 1e9 + 7;

int main() {

	scanf("%d", &n);
	for (int i = 0, j; i < n; i++) {
		scanf("%d", &j);
		num[j]++;
		Max = Max > j ? Max : j;
		Min = Min < j ? Min : j;

	}
	for (int i = Min+1; i <=Max; i++) {
		if (num[i] < 2) {
			continue;
		}
		for (int j = Min; j <= (i / 2); j++) {
			if ((i - j) != j) {
				times += num[i] * (num[i] - 1) * num[j] * num[i - j] / 2 % mod;
			}
			else if (num[j] >= 2 && j * 2 == i) {
				times += num[i] * (num[i] - 1) * num[i / 2] * (num[i / 2] - 1) / 4 % mod;
			}
		}
		times %= mod;;
	}
	printf("%d", times % mod);

	return 0;
}
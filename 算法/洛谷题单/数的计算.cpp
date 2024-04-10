#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int n, arr[1005] = { 0 };

int main() {

	scanf("%d", &n);
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= (i / 2); j++) {
			arr[i] += arr[j];
		}
		arr[i]++;
	}
	printf("%d", arr[n]);

	return 0;
}
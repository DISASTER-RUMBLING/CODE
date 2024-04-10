#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long comp(int* a, int* b) {
	return *a - *b;
}

int main() {
	long long n;
	scanf("%lld", &n);
	long long* arr = (long long*)malloc(n * sizeof(long long));
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	qsort(arr, n, sizeof(long long), comp);
	long long now = arr[n / 2];
	long long result = 0;
	for (long long i = 0; i < n; i++) {
		result += (long long)abs(arr[i] - now);
	}
	printf("%lld", result);

	return 0;
}
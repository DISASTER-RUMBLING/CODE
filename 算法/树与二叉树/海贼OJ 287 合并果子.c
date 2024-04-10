//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int compar(int* a, int* b) {
//	return *a - *b;
//}
//
//int main() {
//	long long n;
//	scanf("%lld", &n);
//	if (n == 0) {
//		printf("0");
//		return 0;
//	}
//	long long* dui = (long long*)malloc(n * sizeof(long long));
//	for (long long i = 0; i < n; i++) {
//		scanf("%lld", &dui[i]);
//	}
//	if (n == 1) {
//		printf("%lld", dui[0]);
//		return 0;
//	}
//	qsort(dui, n, sizeof(long long), compar);
//	long long result = ((n-1)*dui[0]) + ((n-1)*dui[1]);
//	for (long long i = 2; i < n; i++) {
//		result += (n - 2) * dui[i];
//	}
//	printf("%lld", result);
//	return 0;
//}
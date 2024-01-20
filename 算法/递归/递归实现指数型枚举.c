//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int num[10];
//
//void prinf(int i) {
//	for (int k = 0; k <= i; k++) {
//		if (k) {
//			printf(" ");
//		}
//		printf("%d", num[k]);
//	}
//	printf("\n");
//	return;
//}
//
//void arr(int i, int j, int n) {
//	if (j > n) {
//		return;
//	}
//	for (int e = j; e <= n; e++) {
//		num[i] = e;
//		prinf(i);
//		arr(i + 1, e + 1, n);
//	}
//	return;
//}
//
//int main() {
//
//	int num1;
//	scanf("%d", &num1);
//	arr(0, 1, num1);
//
//	return 0;
//}
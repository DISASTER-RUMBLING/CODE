//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int num[8], via[8];
//
//void prinf(int j) {
//	for (int i = 0; i < j; i++) {
//		if (i) {
//			printf(" ");
//		}
//		printf("%d", num[i]);
//	}
//	printf("\n");
//}
//
//void arr(int i, int j) {
//	if (i == j) {
//		prinf(j);
//		return;
//	}
//	for (int e = 1; e <= j; e++) {
//		if (via[e]) {
//			continue;
//		}
//		num[i] = e;
//		via[e] = 1;
//		arr(i + 1, j);
//		via[e] = 0;
//	}
//}
//int main() {
//
//	int num1;
//	scanf("%d", &num1);
//	arr(0, num1);
//
//	return 0;
//}
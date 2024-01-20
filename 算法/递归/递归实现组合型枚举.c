//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int num[10];
//
//void prinf(int f) {
//	for (int g = 0; g < f; g++) {
//		if (g) {
//			printf(" ");
//		}
//		printf("%d", num[g]);
//	}
//	printf("\n");
//}
//
//void arr(int i, int j, int k, int m) {
//	if (j > k && i < m ) {
//		return;
//	}
//	for (int e = j; e <= k; e++) {
//		if (i == m ) {
//			return;
//		}
//		num[i] = e;
//		arr(i + 1, e + 1, k, m);
//		if ((i+1) == m && num[i-1]<num[i] ){
//			prinf(m);
//		}
//	}
//}
//
//int main() {
//
//	int n, m;
//	scanf("%d %d", &n, &m);
//	arr(0, 1, n, m);
//
//	return 0;
//}
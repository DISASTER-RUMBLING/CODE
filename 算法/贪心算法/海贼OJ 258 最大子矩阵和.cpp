#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main() {

	int n, arr[105][105] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i - 1][j];
		}
	}
	int res = -9999999;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int sum = 0;
			for (int k = 1; k <= n; k++) {
				int a = arr[j][k] - arr[i - 1][k];
				if (sum >= 0) {
					sum += a;
				}
				else {
					sum = a;
				}
				if (sum > res) {
					res = sum;
				}
			}
		}
	}
	printf("%d", res);
	
	return 0;

}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int hang;
int arr[1005][1005] = { 0 };
int sum[1005][1005] = { 0 };

int main() {

	scanf("%d", &hang);
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	sum[1][1] = arr[1][1];
	for (int i = 2; i <= hang; i++) {
		for (int j = 1; j <= i; j++) {
			sum[i][j] = max(sum[i - 1][j - 1] + arr[i][j], sum[i - 1][j] + arr[i][j]);
		}
	}
	int res = -1;
	for (int i = 1; i <= hang; i++) {
		res = max(res, sum[hang][i]);
	}
	printf("%d", res);

	return 0;
}
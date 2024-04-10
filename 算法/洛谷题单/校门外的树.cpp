#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main() {

	int l, m;
	scanf("%d%d", &l, &m);
	int arr[101][2], arr1[10000] = { 0 };
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &arr[i][0], &arr[i][1]);
		for (int j = arr[i][0]; j <= arr[i][1]; j++) {
			arr1[j] = 1;
		}
	}
	int time = 0;
	for (int i = 0; i <= l; i++) {
		if (arr1[i] == 0) {
			time++;
		}
	}
	printf("%d", time);

	return 0;
}
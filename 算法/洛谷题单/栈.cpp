#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int arr[20][20] = { 0 };

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		arr[i][0] = 1;
	}
	//i表示列也表示栈内有几个数字，j表示行也表示未入栈的数字有多少个
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i <= n; i++) {
			if (i == 0) {
				arr[i][j] += arr[i + 1][j - 1];
			}
			else {
				arr[i][j] += (arr[i - 1][j] + arr[i + 1][j - 1]);
			}
		}
	}
	printf("%d", arr[0][n]);

	return 0;
}
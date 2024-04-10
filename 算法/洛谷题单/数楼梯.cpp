#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int n;
int arr[5005][5005] = { 0 };

//X表示N-1，Y表示N-2
void Sum(int x, int y) {
	for (int i = 0, flag = 0; i < 5005; i++) {
		arr[x + 1][i] = arr[x][i] + arr[y][i] + flag;
		flag = 0;
		if (arr[x + 1][i] > 9) {
			arr[x + 1][i] %= 10;
			flag = 1;
		}
	}
	return;
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i <= 2) {
			arr[i][0] = i;
		}
		else {
			Sum(i - 1, i - 2);
		}
	}
	for (int i = 5004,flag=0; i >= 0; i--) {
		if (!arr[n][i] && !flag) {
			continue;
		}
		printf("%d", arr[n][i]);
		flag = 1;
	}


	return 0;
}
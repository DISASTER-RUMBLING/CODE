#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int n, m;
int arr[105][105] = { 0 };

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j]) {
				printf("9 ");
			}
			else {
				printf("%d ", arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] +
					arr[i][j - 1] + arr[i][j] + arr[i][j + 1] +
					arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
			}
		}
		printf("\n");
	}

	return 0;
}
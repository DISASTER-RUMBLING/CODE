#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main() {


	int n, m;
	int dir[8][2] = {
		{-1,1},{-1,0},{-1,-1},{0,1},{0,-1},{1,1},{1,0},{1,-1}
	}, vis[105][105] = { 0 };
	char arr[105][105] = { 0 };
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == '*') {
				vis[i][j] = -10;
			}
		}
		getchar();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == '*') {
				for (int k = 0; k < 8; k++) {
					vis[i + dir[k][0]][j + dir[k][1]] += 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (vis[i][j] >= 0) {
				printf("%d", vis[i][j]);
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}

	return 0;
}
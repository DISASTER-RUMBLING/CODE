#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int ans[105][105] = { 0 }, vis[105][105] = { 0 };
int dir[8][2] = {
	{1,1},{-1,-1},{1,0},{0,1},{1,-1},{-1,1},{-1,0},{0,-1}
};
char p[105][105] = { 0 }, str[8] = "yizhong";

void Color(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int flag = 1;
		for (int j = 0; str[j]; j++) {
			int dx = x + j * dir[i][0];
			int dy = y + j * dir[i][1];
			if (str[j] == p[dx][dy]) {
				continue;
			}
			flag = 0;
			break;
		}
		if (flag == 1) {
			for (int j = 0; j < 7; j++) {
				int dx = x + j * dir[i][0];
				int dy = y + j * dir[i][1];
				ans[dx][dy] = 1;
			}
		}
	}
	return;
}

void Deep_Seek(int x, int y) {
	if (p[x][y] == '\0') {
		return;
	}
	if (vis[x][y]) {
		return;
	}
	if (p[x][y] == 'y') {
		Color(x, y);
	}
	vis[x][y] = 1;
	Deep_Seek(x, y + 1);
	Deep_Seek(x + 1, y);
	return;
}


int main() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", p[i] + 1);
	}
	Deep_Seek(1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[i][j]) {
				printf("%c", p[i][j]);
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}

	return 0;

}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int num[4][21] = { 0 }, num1[4], tot;

void dfs(int l, int r, int ke, int deep) {
	if (deep == num1[ke]) {
		tot = min(tot, max(l, r));
		return;
	}
	dfs(l + num[ke][deep], r, ke, deep + 1);
	dfs(l, r + num[ke][deep], ke, deep + 1);
	return;
}

int main() {
	
	scanf("%d%d%d%d", &num1[0], &num1[1], &num1[2], &num1[3]);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < num1[i]; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	int res = 0;
	for (int i = 0; i < 4; i++) {
		tot = 99999999;
		dfs(0, 0, i, 0);
		res += tot;
	}
	printf("%d", res);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;

//sou中第0位为酸度，第一位为苦度
int n, sou[11][2], res = 999999999;
bool use[11] = { 0 };

void dfs(int deep, int suan, int ku) {
	if (deep == n) {
		return;
	}
	for (int i = 0; i < n; i++) {
		int s_suan = suan, s_ku = ku;
		if (!use[i]) {
			use[i] = 1;
			s_suan *= sou[i][0];
			s_ku += sou[i][1];
			res = min(res, abs(s_suan - s_ku));
			dfs(deep + 1, s_suan, s_ku);
			use[i] = 0;
		}
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &sou[i][0], &sou[i][1]);
	}
	dfs(0, 1, 0);
	printf("%d", res);

	return 0;
}
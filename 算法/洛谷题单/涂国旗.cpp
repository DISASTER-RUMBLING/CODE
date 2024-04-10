#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int n, m, step = 99999999;
string q;
//第一位表示前i行全部W色所要的步骤数
//第二位表示前i行全部B色所要的步骤数
//第三位表示前i行全部R色所要的步骤数
int sum[55][3] = { 0 };

int Num(char p) {
	int tot = 0;
	for (int i = 0; i < m; i++) {
		if (q[i] == p) {
			tot++;
		}
	}
	return (m - tot);
}

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin >> q;
		sum[i][0] = sum[i - 1][0] + Num('W');
		sum[i][1] = sum[i - 1][1] + Num('B');
		sum[i][2] = sum[i - 1][2] + Num('R');
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			step = min(step, sum[i][0] + sum[j][1] - sum[i][1] + sum[n][2] - sum[j][2]);
		}
	}
	printf("%d", step);

	return 0;
}
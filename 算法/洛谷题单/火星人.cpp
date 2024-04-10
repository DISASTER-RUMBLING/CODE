#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int n, add, flag = 0, times = 0;
int vis[10005] = { 0 };
bool use[10005] = { 0 };

void Print() {
	for (int i = 0; i < n; i++) {
		if (i) {
			printf(" ");
		}
		printf("%d", vis[i]);
	}
	return;
}

void dfs(int deep) {
	if (!flag && deep == n) {
		flag = 1;
	}
	if (deep == n && flag) {
		times++;
	}
	if (deep == n && times-1 == add) {
		Print();
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		if (!flag) {
			i = vis[deep];
		}
		if (!use[i]) {
			vis[deep] = i;
			use[i] = i;
			dfs(deep + 1);
			vis[deep] = 0;
			use[i] = 0;
		}
	}
	return;
}

int main() {

	scanf("%d", &n);
	scanf("%d", &add);
	for (int i = 0; i < n; i++) {
		scanf("%d", &vis[i]);
	}
	dfs(0);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

int n;
int vis[10] = { 0 };
bool use[10] = { 0 };

void dfs(int deep) {
	if (deep == n) {
		for (int i = 0; i < n; i++) {
			cout << setw(5) << vis[i];
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
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
	dfs(0);


	return 0;
}
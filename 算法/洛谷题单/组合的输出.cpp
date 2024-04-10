#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

int n, r;
int vis[21] = { 0 };
bool use[21] = { 0 };

void dfs(int deep) {
	if (deep-1 == r) {
		for (int i = 1; i <= r; i++) {
			cout << setw(3) << vis[i];
		}
		printf("\n");
		return;
	}
	for (int i = vis[deep-1] + 1; i <= n; i++) {
		vis[deep] = i;
		use[deep] = i;
		dfs(deep + 1);
		vis[deep] = 0;
		use[deep] = 0;
	}
	return;
}

int main() {

	scanf("%d%d", &n, &r);
	dfs(1);

	return 0;
}
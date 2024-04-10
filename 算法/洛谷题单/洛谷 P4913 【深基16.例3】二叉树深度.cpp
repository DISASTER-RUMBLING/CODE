#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct node {
	int l, r;
};

node arr[1000005] = { 0 };
int num, res = 1;

void dfs(int deep, node now) {
	if (now.l == 0 && now.r == 0) {
		res = max(res, deep);
		return;
	}
	if (now.l) {
		dfs(deep + 1, arr[now.l]);
	}
	if (now.r) {
		dfs(deep + 1, arr[now.r]);
	}
}

int main() {

	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d%d", &arr[i].l, &arr[i].r);
	}
	dfs(1, arr[1]);
	printf("%d", res);

	return 0;
}
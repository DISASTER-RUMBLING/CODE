#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node {
	int t, d, l;
};

int n, t;
node arr[15];
bool use[15];

bool dfs(int deep, int now) {
	if (deep > n) {
		return 1;
	}
	for (int i = 0; i < n; i++) {
		if (use[i] || arr[i].t + arr[i].d < now) {
			continue;
		}
		use[i] = 1;
		if (dfs(deep + 1, max(now, arr[i].t) + arr[i].l)) {
			use[i] = 0;
			return 1;
		}
		use[i] = 0;
	}
	return 0;
}

int main() {

	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &arr[i].t, &arr[i].d, &arr[i].l);
		}
		memset(use, 0, sizeof(use));
		if (dfs(1, 0)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}
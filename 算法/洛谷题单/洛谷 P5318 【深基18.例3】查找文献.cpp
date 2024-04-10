#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<queue>
#include<cstring>

using namespace std;

int n, m;
set<int> arr[100005];
bool vis[100005] = { 0 };

void dfs(int now) {
	if (vis[now]) {
		return;
	}
	vis[now] = 1;
	printf("%d ", now);
	for (int i : arr[now]) {
		dfs(i);
	}
	return;
}

void bfs(int beg) {
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		if (vis[now]) {
			continue;
		}
		for (auto x : arr[now]) {
			que.push(x);
		}
		printf("%d ", now);
		vis[now] = 1;
	}
	return;
}

int main() {

	scanf("%d%d", &n, &m);
	while (m--) {
		int last, now;
		scanf("%d%d", &last, &now);
		arr[last].insert(now);
	}
	dfs(1);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	bfs(1);
	printf("\n");

	return 0;
}
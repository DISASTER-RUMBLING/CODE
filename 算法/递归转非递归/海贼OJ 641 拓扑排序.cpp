#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int indeg[2005] = { 0 };
	vector<vector<int>> g(2005);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d %d", &a, &b);
		indeg[b] += 1;
		g[a].push_back(b);
	}
	set<int> q;
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.insert(i);
		}
	}
	int ans = 0, res[2005];
	while (q.size() > 0) {
		int now = *q.begin();
		res[ans++] = now;
		q.erase(now);
		for (int i = 0, k = g[now].size(); i < k; i++) {
			int t = g[now][i];
			indeg[t] -= 1;
			if (indeg[t] == 0) {
				q.insert(t);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i) {
			printf(" ");
		}
		printf("%d", res[i]);
	}

	return 0;
}
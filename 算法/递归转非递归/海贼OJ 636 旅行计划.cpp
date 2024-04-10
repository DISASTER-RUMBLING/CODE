//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int main() {
//	int n, m;
//	int indeg[200005] = { 0 }, ans[200005] = { 0 };
//	vector<vector<int>> p(200005);
//	scanf("%d%d", &n, &m);
//	for (int i = 0, x, y; i < m; i++) {
//		scanf("%d%d", &x, &y);
//		indeg[y] += 1;
//		p[x].push_back(y);
//	}
//	queue<int> q;
//	for (int i = 1; i <= n; i++) {
//		if (indeg[i]) {
//			continue;
//		}
//		q.push(i);
//		ans[i] = 1;
//	}
//	while (!q.empty()) {
//		int now = q.front();
//		q.pop();
//		for (int i = 0, I = p[now].size(); i < I; i++) {
//			int t = p[now][i];
//			indeg[t] -= 1;
//			if (indeg[t] == 0) {
//				q.push(t);
//			}
//			ans[t] = (ans[now] + 1) > ans[t] ? (ans[now] + 1) : ans[t];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		printf("%d\n", ans[i]);
//	}
//
//	return 0;
//}
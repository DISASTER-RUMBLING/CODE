#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<deque>
using namespace std;

int main() {
	int n, m, ans = -9999999;
	scanf("%d%d", &n, &m);
	vector<int> p(n + 1);
	deque<int> q;
	p.push_back(0);
	q.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		p[i] += p[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		ans = ans > (p[i] - p[q.front()]) ? ans : (p[i] - p[q.front()]);
		while (!q.empty() && p[q.back()] > p[i]) {
			q.pop_back();
		}
		q.push_back(i);
		if ((i - m) == q.front()) {
			q.pop_front();
		}
	}
	printf("%d", ans);

	return 0;
}
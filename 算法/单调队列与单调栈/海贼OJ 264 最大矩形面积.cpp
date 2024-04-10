#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<stack>
using namespace std;

int main() {
	long long n;
	scanf("%lld", &n);
	vector<long long> p(n + 2, -1), l(n + 2), r(n + 2);
	stack<long long> q;
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &p[i]);
	}
	for (long long i = 1; i <= n; i++) {
		while (!q.empty() && p[q.top()] > p[i]) {
			r[q.top()] = i;
			q.pop();
		}
		q.push(i);
	}
	while (!q.empty()) {
		q.pop();
	}
	for (long long i = n; i >= 0; i--) {
		while (!q.empty() && p[q.top()] > p[i]) {
			l[q.top()] = i;
			q.pop();
		}
		q.push(i);
	}
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		ans = (ans > (p[i] * (r[i] - l[i] - 1))) ? ans : (p[i] * (r[i] - l[i] - 1));
	}
	printf("%lld", ans);

	return 0;
}
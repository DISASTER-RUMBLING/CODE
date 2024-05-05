#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>

using namespace std;

#define ll long long 

ll n, f[100005] = { 0 };
ll m, p1, s1, s2;
ll l = 0, r = 0, sub, ans, res;

int main() {

	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &f[i]);
	}
	scanf("%lld%lld%lld%lld", &m, &p1, &s1, &s2);
	f[p1] += s1;
	for (ll i = 1; i < m; i++) {
		l += (f[i] * (m - i));
	}
	for (ll i = m + 1; i <= n; i++) {
		r += (f[i] * (i - m));
	}
	if (l < r) {
		sub = r - l;
		ans = 1;
		for (ll i = 1, now = (m-1)*s2; i < m; i++, now -= s2) {
			ans = abs(sub - now) <= abs(sub - (m - ans) * s2) ? i : ans;
		}
		if (sub < abs(((m - ans) * s2) - sub)) {
			printf("%lld", m);
		}
		else {
			printf("%lld", ans);
		}
	}
	else if (l > r) {
		sub = l - r;
		ans = m + 1;
		for (ll i = m + 1, now = s2; i <= n; i++, now += s2) {
			ans = abs(sub - now) <= abs((ans - m) * s2 - sub) ? i : ans;
		}
		if (sub < abs(((ans - m) * s2) - sub)) {
			printf("%lld", m);
		}
		else {
			printf("%lld", ans);
		}
	}
	else {
		printf("%lld", m);
	}

	return 0;
}
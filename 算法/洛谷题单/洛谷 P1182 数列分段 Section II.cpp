#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long

ll n, m, arr[100005] = { 0 }, res;

bool Check(ll mid) {
	ll times = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans + arr[i] > mid) {
			times++;
			ans = 0;
		}
		ans += arr[i];
	}
	return times >= m;
}

int main() {

	scanf("%lld%lld", &n, &m);
	ll l = -1, r = 0;
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		l = max(l, arr[i]);
		r += arr[i];
	}
	while (l <= r) {
		ll mid = l + r >> 1;
		if (Check(mid)) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%lld", l);

	return 0;
}
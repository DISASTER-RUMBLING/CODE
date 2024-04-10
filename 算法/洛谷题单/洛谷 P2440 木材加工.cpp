#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long

ll n, k, arr[100000] = { 0 }, mx = -1, l, r, mid;

bool Check(ll mid) {
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		if (arr[i] < mid) {
			break;
		}
		ans += (arr[i] / mid);
	}
	return ans >= k;
}

int main() {

	scanf("%lld%lld", &n, &k);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		mx = max(arr[i], mx);
	}
	sort(arr, arr + n, greater<ll>());
	l = -1, r = arr[0] + 1, mid = (l + r) >> 1;
	while ((l + 1) < r) {
		if (Check(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
		mid = (l + r) >> 1;
		if (mid == 0) {
			printf("0");
			return 0;
		}
	}
	printf("%lld", l);
	
	return 0;
}
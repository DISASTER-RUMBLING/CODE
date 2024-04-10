#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long

ll ed, n, k, arr[100005] = { 0 }, res, mi = 9999999;

bool Check(ll mid) {
	ll tmp = 0, times = k;
	for (ll i = 0; i < (n - 1); i++) {
		if (times < 0) {
			return false;
		}
		if ((arr[i] - tmp) <= mid) {
			tmp = arr[i];
		}
		else {
			tmp += mid;
			i--, times--;
		}
	}
	if (times < 0) {
		return false;
	}
	return true;
}

int main() {

	//ed表示公路长度，n表示原有路标数量，k表示最多可放置路标数量
	scanf("%lld%lld%lld", &ed, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	ll l = 0, r = ed;
	while (l <= r) {
		ll mid = l + ((r - l) / 2);
		if (Check(mid)) {
			res = mid;
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	printf("%lld", res);

	return 0;
}
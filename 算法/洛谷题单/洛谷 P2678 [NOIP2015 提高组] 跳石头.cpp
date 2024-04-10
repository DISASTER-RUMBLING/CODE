#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define ll long long

//ed表示起点0到终点的距离，n表示起点到终点的过程中有多少个石头，m表示可以移除几个石头
ll ed, n, m, arr[50005] = { 0 }, res = 0;

bool Check(ll mid) {
	ll tmp = 0, now = 0;
	for (ll i = 1; i <= n; i++) {
		if ((arr[i] - arr[now]) < mid) {
			tmp++;
		}
		else {
			now = i;
		}
	}
	if (tmp > m) {
		return 0;
	}
	return 1;
}

int main() {

	scanf("%lld%lld%lld", &ed, &n, &m);
	if (n == 0 || n == m) {
		printf("%lld", ed);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	arr[n + 1] = ed;
	ll l = 0, r = ed, mid = (l + r) >> 1;
	while (l <= r) {
		if (Check(mid)) {
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
		mid = (l + r) >> 1;
	}
	printf("%lld", res);

	return 0;
}
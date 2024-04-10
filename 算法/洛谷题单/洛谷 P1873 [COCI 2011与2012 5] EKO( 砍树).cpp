#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long

ll n, m, arr[1000005] = { 0 }, res = 0, now = 1;

bool Cmp(ll x, ll y) {
	return x > y;
}

int main() {

	scanf("%lld%lld", &n, &m);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n, Cmp);
	while (res < m) {
		res += (arr[now - 1] - arr[now]) * now;
		now++;
	}
	res = arr[now - 1] + ((res - m) / (now - 1));
	printf("%lld", res);
	return 0;
}
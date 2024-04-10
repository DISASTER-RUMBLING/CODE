#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

#define ll long long

ll n, res = 999999999999999;
map<ll, ll> arr;

int main() {

	scanf("%lld", &n);
	for (ll i = 0, num; i < n; i++) {
		scanf("%lld", &num);
		if (arr.find(num) != arr.end()) {
			arr[num] += 1;
		}
		arr.insert({ num,1 });
	}
	ll l_f, l_s = 0, ans = 0, ll_f, ll_s = 0;
	for (auto x : arr) {
		if (l_s == 0) {
			l_f = x.first;
			l_s = x.second;
			ans++;
			continue;
		}
		if (l_f + 1 == x.first) {
			ans++;
			if (l_s > x.second && ll_s<l_s) {
				res = min((long long)1, res);
			}
		}
		else {
			res = min(res, ans);
			ans = 1;
		}
		ll_f = l_f;
		ll_s = l_s;
		l_f = x.first;
		l_s = x.second;
	}
	res = min(res, ans);
	printf("%lld", res);

	return 0;
}
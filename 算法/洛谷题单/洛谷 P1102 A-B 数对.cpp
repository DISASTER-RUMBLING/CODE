#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

#define ll long long 

map<ll, ll> arr;
ll r, c, res = 0;

int main() {

	scanf("%lld%lld", &r, &c);
	for (ll i = 0, j, k = 0; i < r; i++) {
		scanf("%lld", &j);
		arr[j] += 1;
	}
	ll l = 0;
	for (auto x : arr) {
		ll tar = c + x.first;
		if (arr.find(tar) != arr.end()) {
			res += (arr[tar] * x.second);
		}
	}
	printf("%lld", res);

	return 0;
}
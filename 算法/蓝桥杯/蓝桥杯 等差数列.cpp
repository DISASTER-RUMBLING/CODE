#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long

ll n, now, cha;
vector<ll> arr;

ll gcd(ll x, ll y) {
	return !y ? x : gcd(y, x % y);
}

int main() {

	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &now);
		arr.push_back(now);
	}
	sort(arr.begin(), arr.end());
	cha = arr[1] - arr[0];
	if (cha == 0) {
		printf("%lld", n);
		return 0;
	}
	ll sz = arr.size();
	for (int i = 1; i <= sz - 2; i++) {
		cha = gcd(cha,arr[i + 1] - arr[i]);
	}
	printf("%lld", 1 + ((arr[sz - 1] - arr[0]) / cha));

	return 0;
}
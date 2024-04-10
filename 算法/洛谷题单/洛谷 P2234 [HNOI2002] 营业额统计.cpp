#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>

using namespace std;

#define ll long long

ll arr[33000], num, res = 0;

int main() {

	scanf("%lld", &num);
	for (ll i = 0; i < num; i++) {
		scanf("%lld", &arr[i]);
		ll ans = 999999999999;
		for (ll j = 0; j < i; j++) {
			ans = min(ans, abs(arr[j] - arr[i]));
		}
		if (i == 0) {
			res += arr[0];
		}
		else {
			res += ans;
		}
	}
	printf("%lld", res);

	return 0;
}
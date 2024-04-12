#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long

ll res = 0, now;
ll arr[9] = { 1,2,3,4,5,6,7,8,9 };

ll check(ll l,ll r) {
	ll x = 0;
	for (int i = l; i <= r; i++) {
		x = (x * 10) + arr[i];
	}
	return x;
}



int main() {

	scanf("%lld", &now);
	do {
		for (int i = 0; i < 7; i++) {
			ll a = check(0, i);
			for (int j = i + 1; j < 8; j++) {
				ll b = check(i + 1, j);
				ll c = check(j + 1, 8);
				if ((b % c) == 0 && a + (b / c) == now) {
					res++;
				}
			}
		}
	} while (next_permutation(arr, arr + 9));
	printf("%lld", res);

	return 0;
}
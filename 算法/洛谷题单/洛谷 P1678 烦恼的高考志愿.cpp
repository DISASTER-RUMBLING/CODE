#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define ll long long

long long n, m, gus[100000] = { 0 }, tar[100000] = { 0 }, res = 0;

int main() {

	scanf("%lld%lld", &m, &n);
	for (ll i = 0; i < m; i++) {
		scanf("%lld", &tar[i]);
		
	}
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &gus[i]);
	}
	sort(tar, tar + m);
	sort(gus, gus + n);
	for (ll i = 0; i < n; i++) {
		if (gus[i] == 0) {
			res += tar[0];
			continue;
		}
		ll l = 0, r = m, mid = (l + r) >> 1;
		while ((l + 1) < r) {
			if (tar[mid] < gus[i]) {
				l = mid;
			}
			else {
				r = mid;
			}
			mid = (l + r) >> 1;
		}
		if (abs(tar[l] - gus[i]) < abs(tar[r] - gus[i])) {
			res += abs(tar[l] - gus[i]);
		}
		else {
			res += abs(tar[r] - gus[i]);
		}
	}
	printf("%lld", res);

	return 0;
}
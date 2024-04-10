#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long

struct milk {
	ll p, s;
}arr[5005];

ll n, m, res = 0;

bool Cmp(milk p1, milk p2) {
	if (p1.p == p2.p) {
		return p1.s > p2.s;
	}
	return p1.p < p2.p;
}

int main() {

	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%lld%lld", &arr[i].p, &arr[i].s);
	}
	sort(arr, arr + m, Cmp);
	int now = 0;
	while (n > 0) {
		if (n >= arr[now].s) {
			res += (arr[now].s * arr[now].p);
			n -= arr[now].s;
		}
		else if (n < arr[now].s) {
			res += arr[now].p * arr[now].s * ((n * 1.0) / arr[now].s);
			break;
		}
		now++;
	}
	printf("%lld", res);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

long long n, m;
long long arr[1000010];

long long Hlaf_Searcch(long long tar) {
	long long l = 0, r = n + 1;
	while (l + 1 < r) {
		long long mid = (l + r) >> 1;
		if (arr[mid] < tar) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	if (arr[r] == tar) {
		return r;
	}
	else {
		return -1;
	}
	
}

int main() {

	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	while (m--) {
		long long tar;
		scanf("%lld", &tar);
		long long res = Hlaf_Searcch(tar);
		printf("%lld ", res);
	}

	return 0;
}
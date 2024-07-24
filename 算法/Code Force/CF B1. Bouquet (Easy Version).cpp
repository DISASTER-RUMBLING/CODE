#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int times;
	scanf("%d", &times);
	while (times--) {
		long long n, m;
		scanf("%lld%lld", &n, &m);
		vector<long long> arr(n, 0);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}
		sort(arr.begin(), arr.end());
		if (arr[0] > m) {
			printf("0\n");
			continue;
		}
		long long l = 0, res = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			m -= arr[i];
			ans += arr[i];
			while ((arr[i] - arr[l] > 1 || m < 0) && l<=i) {
				m += arr[l];
				ans -= arr[l];
				l++;
			}
			res = max(res, ans);
		}
		printf("%lld\n", res);
	}

	return 0;
}
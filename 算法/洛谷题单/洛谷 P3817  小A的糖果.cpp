#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long
long long n, x, res = 0, arr[100005] = { 0 };

int main() {

	scanf("%lld%lld", &n, &x);
	for (long long i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	for (long long i = 1; i <= n; i++) {
		if ((arr[i - 1] + arr[i]) > x) {
			ll sp = arr[i - 1] + arr[i] - x;
			res += sp;
			if (arr[i] >= sp) {
				arr[i] -= sp;
			}
			else {
				sp -= arr[i];
				arr[i] = 0;
				arr[i - 1] -= sp;
			}
		}
	}
	printf("%lld", res);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define ll long long

ll n, m;
ll num[105] = { 0 };
ll arr[105][10005] = { 0 };

int main() {

	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &num[i]);
	}
	//i表示枚举到第i个菜,j表示有多少钱
	for (ll i = 1;i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (j == num[i]) {
				arr[i][j] = arr[i - 1][j] + 1;
			}
			else if (j > num[i]) {
				arr[i][j] = arr[i - 1][j - num[i]] + arr[i - 1][j];
			}
			else {
				arr[i][j] = arr[i - 1][j];
			}
		}
	}
	printf("%lld", arr[n][m]);

	return 0;
}
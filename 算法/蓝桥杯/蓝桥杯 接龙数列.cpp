#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define ll long long

ll n, arr[10] = { 0 };
string num;
ll res = 0;

int main() {

	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num[num.size() - 1] - '0'] = max(arr[num[num.size() - 1] - '0'], arr[num[0] - '0'] + 1);
	}
	for (int i = 0; i < 10; i++) {
		res = max(res, arr[i]);
	}
	printf("%lld", n - res);

	return 0;
}
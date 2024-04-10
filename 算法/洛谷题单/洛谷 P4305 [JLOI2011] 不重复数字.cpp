#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

#define ll long long

int num, n;

int main() {

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &num);
		unordered_map<ll, bool> arr;
		vector<ll> res;
		while (num--) {
			ll now;
			scanf("%lld", &now);
			if (!arr.count(now)) {
				arr[now] = 1;
				printf("%lld ", now);
			}
		}
		printf("\n");
	}

	return 0;
}
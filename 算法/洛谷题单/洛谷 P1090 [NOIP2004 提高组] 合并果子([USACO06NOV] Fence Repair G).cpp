#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
long long now, res = 0;
priority_queue<long long, vector<long long>, greater<long long>> arr;

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &now);
		arr.push(now);
	}
	while (arr.size() != 1) {
		long long x = arr.top();
		arr.pop();
		long long y = arr.top();
		arr.pop();
		res += (x + y);
		arr.push(x + y);
	}
	printf("%lld", res);

	return 0;
}
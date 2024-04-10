#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1005] = { 0 }, num[1005] = { 0 };
long long res = 0, ans = 0;

bool Cmp(int x, int y) {
	return arr[x] < arr[y];
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		num[i] = i;
	}
	sort(num + 1, num + n + 1, Cmp);
	for (int i = 1; i <= n; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
	for (int i = 2; i <= n; i++) {
		ans += arr[num[i-1]];
		res += ans;
	}
	printf("%.2f", (res * 1.0) / n);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int left[1005], right[1005], ind[1005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", left[i], right[i]);
		ind[i] = i;
	}
	sort(ind + 1, ind + n + 1, [&](int i, int j)->bool {
		return left[i] * right[i] < left[j] * right[j];
		});
	long long result = left[0], ans = 0;
	for (int i = 1; i < n; i++) {
		if (result / right[ind[i]] > ans) {
			ans = result / right[ind[i]];
		}
		result *= left[ind[i]];
	}
	printf("%d", ans);

	return 0;
}
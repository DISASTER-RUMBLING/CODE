#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	long long arr[100050];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (i) {
			printf(" ");
		}
		printf("%lld", arr[i]);
	}

	return 0;
}

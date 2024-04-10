#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main() {

	int n, times = 0;
	int arr[10000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				times++;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	printf("%d", times);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main() {

	long long p;
	scanf("%lld", &p);
	int arr[100005] = { 0 }, len = 1;
	arr[0] = 1;
	for (long long i = 0; i < p; i++) {
		int flag = 0;
		for (int j = 0; j < len; j++) {
			arr[j] = arr[j] * 2 + flag;
			if (arr[j] > 9) {
				flag = (arr[j] / 10);
				arr[j] %= 10;
				if (j + 1 == len) {
					len++;
				}
			}
			else {
				flag = 0;
			}
		}
	}
	printf("%d\n", len);
	int time = 0;
	arr[0]--;
	for (len = 499; len >= 0; len--) {
		printf("%d", arr[len]);
		time++;
		if (time == 50) {
			printf("\n");
			time = 0;
		}
	}

	return 0;
}
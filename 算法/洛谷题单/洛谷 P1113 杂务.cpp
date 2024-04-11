#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int n, res = 0;
int arr[10005];

int main() {

	scanf("%d", &n);
	while (n--) {
		int num, len, last;
		scanf("%d %d", &num, &len);
		int tmp = 0;
		while (scanf("%d", &last) && last != 0) {
			tmp = max(tmp, arr[last]);
		}
		arr[num] = tmp + len;
		res = max(arr[num], res);
	}
	printf("%d", res);

	return 0;
}
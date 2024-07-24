#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	int times;
	scanf("%d", &times);
	while (times--) {
		int n, k;
		scanf("%d%d", &n, &k);
		if (k == 0) {
			printf("0\n");
			continue;
		}
		int res = 1;
		k -= (n--);
		while (k > 0 && n > 0) {
			if (k <= n) {
				res++;
				k -= n;
			}
			else {
				res += 2;
				k -= (2 * n);
			}
			n--;
		}
		printf("%d\n", res);
	}

	return 0;
}
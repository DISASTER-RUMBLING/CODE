#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int num, now, res = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &now);
		if (now == 2) {
			res++;
		}
	}
	printf("%d\n", res);

	return 0;
}
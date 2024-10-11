#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int num, res = 1;
	scanf("%d", &num);
	for (int i = 2; i <= num; i++) {
		res *= i;
	}
	printf("%d", res);

	return 0;
}
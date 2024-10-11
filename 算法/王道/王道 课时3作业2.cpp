#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int i;
	char j;
	float k;
	scanf("%d %c %f", &i, &j, &k);
	printf("%.2f\n", (float)((float)i + (float)j + k));

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int num;
	int arr[10] = { 1,2,0 };
	scanf("%d", &num);
	for (int i = 2; i < num; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%d", arr[num - 1]);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {

	int num;
	char c;
	scanf("%d", &num);
	scanf("%c", &c);
	char* p = (char*)malloc(1+num);
	fgets(p, num + 1, stdin);
	printf("%s\n", p);

	return 0;
}
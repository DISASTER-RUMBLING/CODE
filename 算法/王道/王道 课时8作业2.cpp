#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main() {

	char* p = (char*)malloc(100);
	fgets(p, 100, stdin);
	printf("%s", p);

	return 0;
}
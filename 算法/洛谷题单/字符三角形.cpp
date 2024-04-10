#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main() {

	char p;
	scanf("%c", &p);
	printf("  %c\n", p);
	printf(" %c%c%c\n", p, p, p);
	printf("%c%c%c%c%c", p, p, p, p, p);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	char p;
	int res = 0;
	while (scanf("%c", &p) && p != '\n') {
		if (p!=' ' && p!='\n') {
			res++;
		}
	}
	printf("%d", res);

	return 0;
}
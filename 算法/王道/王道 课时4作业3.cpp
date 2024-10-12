#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int num1, num2, num3, num4,res = 0;
	for (num1 = 1; num1 < 10; num1++) {
		for (num2 = 1; num2 < (100-num1*10)/5; num2++) {
			for (num3 = 1; num3 <= (100-num1*10+num2*5)/2; num3++) {
				for (num4 = 1; num4 <= 100 - num1*10 - num2*5 - num3*2; num4++) {
					if (num1 + num2 + num3 + num4 == 40 && (num1 * 10 + num2 * 5 + num3 * 2 + num4) == 100) {
						res++;
					}
				}
			}
		}
	}
	printf("%d\n", res);

	return 0;
}
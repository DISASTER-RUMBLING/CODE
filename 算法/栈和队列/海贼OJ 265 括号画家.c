#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	char arr1[10000], arr2[10000], arr3[10000] = { 0 }, arr4[10000];
	int i = 0, j = 0, flag = 0, max_sum = 0, sum = 0, t = 0, p = 0;
	scanf("%s", arr1);
	while (arr1[i] != '\0') {
		switch (arr1[i]) {
		case '(':
		case '[':
		case '{': {
			arr2[j] = arr1[i];
			p = i;
			j++;
			break;
		}
		case ')': {
			if (j > 0 && arr2[j - 1] == '(') {
				arr3[t] = arr3[t + 1] = 1;
				t += 2;
				j--;
				break;
			}
			else {
				t += 2;
				j = 0;
			}
		}
		case ']': {
			if (j > 0 && arr2[j - 1] == '[') {
				arr3[t] = arr3[t + 1] = 1;
				t += 2;
				j--;
				break;
			}
			else {
				t += 2;
				j = 0;
			}
		}
		case '}':
			if (j > 0 && arr2[j - 1] == '{') {
				arr3[t] = arr3[t + 1] = 1;
				t += 2;
				j--;
				break;
			}
			else {
				t += 2;
				j = 0;
			}
		}
		i++;
	}
	for (int i = 0; i < t; i++) {
		if (arr3[i]) {
			sum++;
		}
		else {
			if (max_sum < sum) {
				max_sum = sum;
			}
			sum = 0;
		}
	}
	if (sum > max_sum) {
		max_sum = sum;
	}
	printf("%d", max_sum);

	return 0;
}
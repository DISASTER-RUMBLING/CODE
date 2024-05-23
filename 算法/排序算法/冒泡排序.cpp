#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Swap(int* x, int* y) {
	int* tmp = x;
	x = y;
	y = tmp;
	return;
}

int* Bubble_Sort(int* arr, int begin, int end) {
	for (int i = 0; i < (end - begin); i++) {
		int flag = 1;
		for (int j = begin; j < end - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
	}
	return arr;
}
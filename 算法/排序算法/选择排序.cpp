#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Swap(int* x, int* y) {
	int* tmp = x;
	x = y;
	y = tmp;
}

int* Choice_Sort(int* arr, int begin, int end) {
	//begin为交换区域的起始位置，end为交换区域的终止位置
	for (int i = begin; i < end - 1; i++) {
		int now = i;
		for (int j = i + 1; j < end; j++) {
			if (arr[j] < arr[now]) {
				now = j;
			}
		}
		Swap(&arr[i], &arr[now]);
	}
	return arr;
}
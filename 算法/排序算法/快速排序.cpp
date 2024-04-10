#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Swap(int* x, int* y) {
	int* tmp = x;
	x = y;
	y = tmp;
	return;
}

int* Quick_Sort(int* arr, int begin, int end) {
	if ((end - begin) <= 2) {
		if (arr[begin] > arr[end]) {
			Swap(&arr[begin], &arr[end]);
		}
		return arr;
	}
	int left = begin + 1, right = end -1, now = begin;
	while (left < right) {
		while (arr[right] > arr[now] && left < right) {
			right--;
		}
		if (left < right) {
			Swap(&arr[right], &arr[now]);
		}
		now = right;
		while (arr[left] < arr[now] && left < right) {
			left++;
		}
		if (left < right) {
			Swap(&arr[left], &arr[now]);
		}
		now = left;
	}
	Quick_Sort(arr, begin, left);
	Quick_Sort(arr, left + 1, end);
	return arr;
}
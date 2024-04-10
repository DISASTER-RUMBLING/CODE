#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int arr1[1000000];

void Swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}

int* Merge_Sort(int* arr, int begin, int end) {
	if ((begin - end) <= 1) {
		if (arr[begin] > arr[end]) {
			Swap(arr + begin, arr + end);
		}
		return arr;
	}
	int mid = (begin + end) / 2;
	Merge_Sort(arr, begin, mid);
	Merge_Sort(arr, mid, end);
	int p1 = begin, p2 = mid, i = 0;
	while (p1 < mid || p2 < end) {
		if (arr[p1] <= arr[p2] || p2 == end) {
			arr1[i++] = arr[p1++];
		}
		else {
			arr1[i++] = arr[p2++];
		}
	}
	for (int i = 0; i < (end - begin); i++) {
		arr[i] = arr1[i];
	}

	return arr;
}
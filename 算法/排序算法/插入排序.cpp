#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Swap(int* x, int* y) {
	int* tmp = x;
	x = y;
	y = tmp;
	return;
}

int* Insert_Sort(int* arr, int begin, int end) {
	for (int i = begin + 1; i < end; i++) {
		int j = i;
		while (j > begin && arr[j] > arr[j + 1]) {
			Swap(&arr[j], &arr[j - 1]);
			j -= 1;
		}
	}
	return arr;
}


//ÎŞ¼à¶½µÄ²åÈëÅÅĞò
int* Unguard_Insert_Sort(int* arr, int begin, int end) {
	int ind = begin;
	for (int i = begin + 1; i < end; i++) {
		if (arr[ind] > arr[i]) {
			ind = i;
		}
	}
	while (ind > begin) {
		Swap(&arr[ind], &arr[ind - 1]);
		ind--;
	}
	for (int i = begin + 1; i < end; i++) {
		int j = i;
		while (arr[j] > arr[j - 1]) {
			Swap(&arr[j], &arr[j - 1]);
			j -= 1;
		}
	}
	return arr;
}
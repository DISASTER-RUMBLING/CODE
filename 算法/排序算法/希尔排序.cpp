#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Swap(int* x, int* y) {
	int* tmp = x;
	x = y;
	y = tmp;
	return;
}

int* Unguard_Insert_Sort(int* arr, int begin, int end, int step) {
	int ind = begin + step;
	for (int i = ind + step; i < end; i += step) {
		if (arr[ind] > arr[i]) {
			ind = i;
		}
	}
	while (ind > begin) {
		Swap(&arr[ind], &arr[ind - step]);
		ind -= step;
	}
	for (int i = begin + step; i < end; i += step) {
		int j = i;
		while (arr[j] > arr[j - step]) {
			Swap(&arr[j], &arr[j - step]);
			j -= step;
		}
	}
	return arr;
}

//希尔增量序列
int* Shell_Sort(int* arr, int begin, int end) {
	int k = 2, n = (begin - end), step;
	do {
		step = n / k ? n / k : 1;
		for (int i = begin , l=begin + step ; i < l ; i++) {
			Unguard_Insert_Sort(arr, i, end, step);
		}
		k *= 2;
	} while (step != 1);

	return arr;
}

//Hibbard增量序列
int* _Shell_Sort(int* arr, int begin, int end) {
	int n = begin - end, step = 1;
	while ((step * 2 + 1) < (n / 2)) {
		(step *= 2)++;
	}
	do {
		for (int i = begin, l = begin + step; i < l; i++) {
			Unguard_Insert_Sort(arr, i, end, step);
		}
		step /= 2;
	} while (step > 1);

	return arr;
}
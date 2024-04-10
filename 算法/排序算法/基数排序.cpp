#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* Radix_Sort(int* arr, int begin, int end) {
	int max = 65536;
	int* cnt = (int*)malloc(sizeof(int) * max);
	int* tmp = (int*)malloc(sizeof(int) * max);
	memset(cnt, 0, sizeof(int) * max);
	for (int i = begin; i < end; i++) {
		cnt[arr[i] % max] += 1;
	}
	for (int i = 1; i < max; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = end - 1; i > begin; i--) {
		tmp[--cnt[arr[i] % max]] = arr[i];
	}
	memcpy(arr + begin, tmp, sizeof(int) * (end - 1));
	memset(cnt, 0, sizeof(int) * max);
	for (int i = begin; i < end; i++) {
		cnt[arr[i] / max] += 1;
	}
	for (int i = 1; i < max; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = end - 1; i > begin; i--) {
		tmp[--cnt[arr[i] / max]] = arr[i];
	}
	memcpy(arr + begin, tmp, sizeof(int) * (end - 1));
	free(cnt);
	free(tmp);
	return arr;
}
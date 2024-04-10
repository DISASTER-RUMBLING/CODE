#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>

int* Init_Color(int n) {
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	return arr;
}

int Find_Color(int* arr, int x) {
	return arr[x];
}

bool Merge(int* arr, int x, int y) {
	int num = sizeof(arr) / sizeof(arr[0]);
	if (x >= num || y >= num) {
		return false;
	}
	int color_x = Find_Color(arr, x), color_y = Find_Color(arr, y);
	if (color_x == color_y) {
		return true;
	}
	for (int i = 0; i < num; i++) {
		//将x的颜色变为y的颜色
		if (arr[i] == color_x) {
			arr[i] = color_y;
		}
	}
	return true;
}
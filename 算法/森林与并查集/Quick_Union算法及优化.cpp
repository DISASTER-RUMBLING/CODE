#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>

int* Init_Color(int n) {
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	return arr;
}

int Find(int* arr, int x) {
	return arr[x] == x ? x : Find(arr, arr[x]);
}

bool Union(int* arr, int x, int y) {
	int root_x = Find(arr, x), root_y = Find(arr, y);
	if (root_x == root_y) {
		return false;
	}
	//将x作为y的父节点
	arr[root_x] = root_y;
	return true;
}


//优化
//size数组中存储的是以第i个节点为根节点的树中有多少个子树
//Find_为路径优化

int size[5000];

int* Init_Color_(int n) {
	int* p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i <= n; i++) {
		size[i] = 1;
	}
	return p;
}

int Find_(int* arr, int n) {
	return arr[n] = arr[n] == n ? n : Find_(arr, arr[n]);
}

bool Merge_(int* arr, int x, int y) {
	int xx = Find(arr, x), yy = Find(arr, y);
	if (arr == NULL || arr[xx] == arr[yy]) {
		return false;
	}
	if (size[xx] > size[yy]) {
		arr[yy] = xx;
		size[xx] += size[yy];
	}
	else {
		arr[xx] = yy;
		size[yy] += size[xx];
	}
	return true;
}
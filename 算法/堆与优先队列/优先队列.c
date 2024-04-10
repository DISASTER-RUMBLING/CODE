#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//假设是大顶堆
//大顶堆:对于该节点及其子节点，该节点的数据总是最大的

typedef struct ProQueue {
	int* data,_data;
	int size, count;
}ProQueue;

ProQueue* Init(int n) {
	ProQueue* p = (ProQueue*)malloc(sizeof(ProQueue));
	p->_data = (int*)malloc(sizeof(int) * n);
	p->data = p->_data - 1;
	p->size = n;
	p->count = 0;
	return p;
}

int Empty(ProQueue* p) {
	return !p->count;
}

int Full(ProQueue* p) {
	return p->count == p->size;
}

void Swap(int* a, int* b) {
	int* tmp = b;
	*b = *a;
	a = *tmp;
}

void Down_Update(int* data, int q) {
	int now = 2 * q;
	if (now > sizeof(data)) {
		return;
	}
	int index = data[2 * q] > data[(2 * q) + 1] ? (2 * q) + 1 : (2 * q);
	if (data[q] > data[index]) {
		Swap(data[q], data[index]);
		Down_Update(data, index);
	}
	return;
}

void Up_Update(int* data, int q) {
	if (q == 1) {
		return;
	}
	if (data[q] > data[q / 2]) {
		Swap(data[q], data[q / 2]);
		Up_Update(data, q / 2);
	}
	return;
}

int Pop(ProQueue* p) {
	if (Empty(p)) {
		return 0;
	}
	Swap(p->data[1], p->data[p->count]);
	p->data[p->count] = NULL;
	Down_Update(p, 1);
	p->count--;
	return 1;
}

int Insert(int n, ProQueue* p) {
	if (Full(p)) {
		return 0;
	}
	p->data[++p->count] = n;
	Up_Update(p, p->count);
	return 1;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
	int freq;
	char ch;
	tree* kid, * bro;
}tree;

tree* Init(int val, char w) {
	tree* p = (tree*)malloc(sizeof(tree));
	p->freq = val;
	p->ch = w;
	p->kid = p->bro = NULL;
	return p;
}

tree** arr[10];

//假设存在一个结构体指针数组，存有各字符及其出现频率的结构体地址
tree* HaffmanTree(tree** arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if ((*arr[j])->freq > (*arr[j + 1])->freq) {
				tree* tmp = (*arr[j]);
				*arr[j] = *arr[j + 1];
				*arr[j] = tmp;
			}
		}
	}
	tree* last = NULL, * p, * root;
	for (int i = 0; i < n - 1; i++) {
		tree* p = Init(NULL, NULL);
		if (last) {
			last->bro = p;
		}
		p->kid = *arr[i];
		last = p;
		if (i == 0) {
			root = p;
		}
	}
	last->bro = *arr[n - 1];
	return root;
}

void Free(tree* p) {
	if (p == NULL) {
		return;
	}
	Free(p->kid);
	Free(p->bro);
	free(p);
	return;
}
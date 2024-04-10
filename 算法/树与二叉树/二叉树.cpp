#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct tree {
	int data;
	tree* bro, * kid;
}tree;

tree* Init_Tree(int val) {
	tree* p = (tree*)malloc(sizeof(tree));
	p->data = val;
	return p;
}

tree* Insert(tree* p, int val) {
	if (p == NULL) {
		return Init_Tree(val);
	}
	srand(time(0));
	if (rand() % 2 == 1) {
		p->kid = Insert(p->kid, val);
	}
	else {
		p->bro = Insert(p->bro, val);
	}
	return p;
}

void Free(tree* p) {
	if (p == NULL) {
		return;
	}
	Free(p->bro);
	Free(p->kid);
	return;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct tree {
	int data;
	tree* kid, * bro;
}tree;

tree* Init(int val) {
	tree* p = (tree*)malloc(sizeof(tree));
	p->data = val;
	p->kid = p->bro = NULL;
	return p;
}

tree* Insert(tree* p, int val) {
	if (p == NULL) {
		return Init(val);
	}
	srand(time(NULL));
	if (rand() % 2 == 0) {
		p->kid = Insert(p->kid, val);
	}
	else {
		p->bro = Insert(p->bro, val);
	}
	return p;
}

//前序遍历
void Pre_order(tree* p) {
	if (p == NULL) {
		return;
	}
	printf("%d ", p->data);
	Pre_order(p->kid);
	Pre_order(p->bro);
	return;
}

//中序遍历
void In_order(tree* p) {
	if (p == NULL) {
		return;
	}
	In_order(p->kid);
	printf("%d ", p->data);
	In_order(p->bro);
	return;
}

//后序遍历
void Post_order(tree* p) {
	if (p == NULL) {
		return;
	}
	Post_order(p->kid);
	Post_order(p->bro);
	printf("%d ", p->data);
	return;
}

void Free(tree* p) {
	if (p == NULL) {
		return;
	}
	Free(p->kid);
	Free(p->bro);
	free(p);
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
	int data;
	tree* bro, * kid;
}tree;

tree* queue[10];

void Ghuang_du_you_xian(tree* p) {
	if (p == NULL) {
		return;
	}
	int head = 0, tail = 0;
	queue[tail++] = p;
	while (head<tail){
		tree* now = queue[head++];
		if (now->kid) {
			queue[tail++] = now->kid;
		}
		if (now->bro) {
			queue[tail++] = now->bro;
		}
	}
	return;
}

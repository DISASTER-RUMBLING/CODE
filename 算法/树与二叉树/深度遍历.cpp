#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct tree {
	int data;
	tree* bro, * kid;
}tree;

tree* queue[10];

void Sheng_DU_You_Xiang(tree* p) {
	if (p == NULL) {
		return;
	}
	printf("%d ", p->data);
	if (p->kid) {
		Sheng_DU_You_Xiang(p->kid);
	}
	if (p->bro) {
		Sheng_DU_You_Xiang(p->bro);
	}
	return;
}
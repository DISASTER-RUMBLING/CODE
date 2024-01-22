#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	Node* next;
}Node;

typedef struct queue {
	Node* l;
	int count;
}queue;

queue* Queue_Init(int val) {
	queue* p = (queue*)malloc(sizeof(queue));
	//
	p->l=Node_Init(val);
	p->count = 0;
	return p;
}

int Empty(queue* p) {
	return (p->l->next == NULL);
}

int Queue_Front(queue* p) {
	return p->l->data;
}

int Queue_Push(queue* p, int val) {
	if (!p) {
		return 0;
	}
	Node* q = p->l->next;
	while ( q->next ) {
		q = q->next;
	}
	//假定有一个函数Node_Init，需要传入一个整形，该整形会被存入新建立的链表节点中
	//并且该函数会返回该节点的地址
	q->next = Node_Init(val);
	p->count += 1;
	return 1;
}

int Queue_Pop(queue* p) {
	if (p || p->l) {
		return 0;
	}
	Node* q = p->l;
	p->l = p->l->next;
	p->count -= 1;
	free(q);
	return 1;
}

void Queue_Free(queue* p) {
	if (!p) {
		return NULL;
	}
	Node_Free(p->l);
	free(p);
}
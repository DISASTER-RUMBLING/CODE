#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int* data;
	int size, top;
}stack;

stack* Stack_Init(int n) {
	stack* p = (stack*)malloc(sizeof(stack));
	p->data = (int*)malloc(sizeof(int) * n);
	p->size = n;
	p->top = -1;
	return p;
}

int Empty(stack* p) {
	if (p == NULL) {
		return NULL;
	}
	return (p->top == -1);
}

int top(stack* p) {
	if (p->top == -1) {
		return NULL;
	}
	return p->data[p->top];
}

int Stack_Push(int val, stack* p) {
	if ( (p->top) + 1 == p->size || p == NULL) {
		return 0;
	}
	p->data[p->top + 1] = val;
	p->top += 1;
	return 1;
}

int Stack_Delete(stack* p) {
	if (Empty(p) ==0) {
		return 0;
	}
	p->data[(p->top) + 1] = NULL;
	p->top -= 1;
	return 1;
}

void Stack_Free(stack* p) {
	if (p == NULL) {
		return;
	}
	free(p->data);
	free(p);
	return;
}
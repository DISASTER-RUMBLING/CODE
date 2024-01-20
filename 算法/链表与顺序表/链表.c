#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* Next;
}Node;

Node* GetNewNode(int val) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = val;
	p->Next = NULL;
	return p;
}

Node* Insert(Node* head, int pos, int val) {
	if (pos == 0) {
		Node* p = GetNewNode(val);
		p->Next = head;
		return p;
	}
	Node* p = head;
	for (int i = 0; i < pos - 1; i++) {
		p = p->Next;
	}
	Node* q = GetNewNode(val);
	q->Next = p->Next;
	p->Next = q;
	return head;
}

Node* Delete(Node* head, int pos) {
	if (pos == 0) {
		return;
	}
	Node* p = head;
	for (int i = 0; i < pos - 1; i++) {
		p = p->Next;
	}
	Node* q = p->Next;
	p->Next = q->Next;
	return head;
}

int Check(Node* head, int val) {
	Node* p = head;
	int n = 0;
	for (; p; p = p->Next) {
		if (p->data == val) {
			return n;
		}
		n++;
	}
	return NULL;
}

void Free(Node *head) {
	if (head == NULL) {
		return;
	}
	for (Node *p = head, *q; p; p = q) {
		q = p->Next;
		free(p);
	}
	return;
}
int main() {

}
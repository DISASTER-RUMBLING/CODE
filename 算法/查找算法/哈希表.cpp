#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<string>
using namespace std;

struct List {
	char* val;
	List* next;

};

struct Hash_Table {
	List* data;
	int size, cnt;

};

List* Init_List(char* key) {
	List* p = (List*)malloc(sizeof(List));
	p->val = key;
	return p;
}

Hash_Table* Init_Hash_Table(int n) {
	Hash_Table* p = (Hash_Table*)malloc(sizeof(Hash_Table));
	p->data = (List*)malloc(sizeof(List) * n);
	p->size = n;
	p->cnt = 0;
	return p;
}

int Hash_Num(char* p) {
	int seed = 131, h = 0;
	for (int i = 0; p[i]; i++) {
		h = h * seed + p[i];
	}
	return h & 0x7fffffff;
}

Hash_Table* Hash_Expand(Hash_Table* p) {
	Hash_Table* q = Init_Hash_Table(p->size * 2);
	for (int i = 0; i < p->size; i++) {
		q->data[i] = p->data[i];
	}
	q->cnt = p->cnt;
	return q;
}

Hash_Table* Insert(char* key, Hash_Table* p) {
	if (p->cnt >= 2 * p->size) {
		p = Hash_Expand(p);
	}
	int code = Hash_Num(key), ind = code % p->size;
	List* new_ = Init_List(key);
	new_->next = p->data[ind].next;
	p->data[ind].next = new_;
	return p;
}

bool Find(Hash_Table* p, char* q) {
	for (int i = 0; i < p->size; i++) {
		List* p1 = p->data[i].next;
		while (p1) {
			if (strcmp(p1->val, q)) {
				return true;
			}
			else {
				p1 = p1->next;
			}
		}
	}
	return false;
}

void Free_List(List* p) {
	if (p == NULL) {
		return;
	}
	List* p1 = p, *p2 = p->next;
	while (p1) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	return;
}

void Free_Hash_Table(Hash_Table* p) {
	if (p == NULL) {
		return;
	}
	while (p->cnt--) {
		Free_List(p->data+p->cnt);
	}
	return;
}
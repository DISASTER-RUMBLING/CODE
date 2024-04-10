#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<inttypes.h>
#include<random>
#include<time.h>
using namespace std;

struct Leap_List {
	int val, level;
	Leap_List* next, * down, * up;

};

struct Skip_List {
	Leap_List* head, * tail;
	int max_level;

};

Leap_List* Init_Leap_List(int val, int grade) {
	Leap_List* p = (Leap_List*)malloc(sizeof(Leap_List) * grade);
	for (int i = 0; i < grade; i++) {
		p[i].val = val;
		p[i].level = i;
		p[i].next = NULL;
		p[i].up = (i ? p + i - 1 : NULL);
		p[i].down = (1 + i < grade ? p + i + 1 : NULL);
	}
	return p;
}

Skip_List* Init_Skip_List(int n) {
	Skip_List* p = (Skip_List*)malloc(sizeof(Skip_List) * n);
	p->max_level = n;
	//此处的head指向最小值的最上端,尾部也是
	//                 head此处->(-1)          (1)<-tail在此处
	//                            -1            1
	//                            -1            1
	//                            -1            1
	//                            -1            1

	p->head = Init_Leap_List(INT32_MIN, n);
	p->tail = Init_Leap_List(INT32_MAX, n);
	Leap_List* p1 = p->head, * p2 = p->tail;
	while (p1) {
		p1->next = p2;
		p1 = p1->down;
		p2 = p2->down;
	}
	return p;
}

Skip_List* Delete(Skip_List* p, int key) {
	Leap_List* q = Find(key, p), * p1 = p->head, * p2 = q, * p3 = q;
	int level_ = 1;
	while (p2->down) {
		level_++;
		p2 = p2->down;
	}
	int down_ = p->max_level - level_;
	while (down_--) {
		p1 = p1->down;
	}
	while (p1) {
		p2 = p1->down;
		while (1) {
			if (p1->val != key) {
				p1 = p1->next;
			}
			else {
				break;
			}
		}
		p1->next = q->next;
		p1 = p2;
		q = q->down;
	}
	free(p3);
	return p;
}

Leap_List* Find(int target, Skip_List* p) {
	Leap_List* q = p->head;
	while (q && q->val != target) {
		if (q->next->val <= target) {
			q = q->down;
		}
		else {
			q = q->next;
		}
	}
	return q;
}

Skip_List* Insert(Skip_List* p, int key) {
	int level_ = rand() % p->max_level;
	Leap_List* q = Init_Leap_List(key, level_), * p1 = p->head;
	while (p1->level + 1 != level_) {
		if (1 + p1->level < level_) {
			p1 = p1->up;
		}
		else {
			p1 = p1->down;
		}
	}
	while (p1) {
		Leap_List* p2 = p1->down;
		while (1) {
			if (p1->next->val >= key) {
				break;
			}
			else {
				p1 = p1->next;
			}
		}
		q->next = p1->next;
		p1->next = q;
		p1 = p2, q = q->down;
	}
	return p;
}

void Free_Leap_List(Leap_List* s) {
	if (s == NULL) {
		return;
	}
	free(s);
	return;
}

void Free_Skip_List(Skip_List* s) {
	Leap_List* q = s->head, * p;
	while (q->level != 0) {
		q = q->down;
	}
	while (q) {
		p = q->next;
		while (q->up) {
			q = q->up;
		}
		Free_Leap_List(q);
		q = p;
	}
	return;
}
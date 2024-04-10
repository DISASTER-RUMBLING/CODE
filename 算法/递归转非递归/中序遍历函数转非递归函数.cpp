#define _CRT_SECURE_NO_WARNINGS
#include<stack>
using namespace std;

struct tree {
	int val;
	tree* bro, * kid;

};

//µÝ¹é°æ±¾
void In_Order(tree* p) {
	if (p == NULL) {
		return;
	}
	In_Order(p->kid);
	printf("%d ", p->val);
	In_Order(p->bro);
	return;
}

//·ÇµÝ¹é°æ±¾
struct dat {
	int code;
	tree* p;
};

dat* Data(tree* p) {
	dat* q = (dat*)malloc(sizeof(dat));
	q->code = 0;
	q->p = p;
	return q;
}

void Non_In_Order(tree* p) {
	dat* q = Data(p);
	stack<dat*> s;
	s.push(q);
	while (!s.empty()) {
		dat* j = s.top();
		switch (j->code) {
		case 0: {
			if (j->p == NULL) {
				s.pop();
			}
			else {
				j->code = 1;
			}
		}break;
		case 1: {
			dat* k = Data(j->p->kid);
			s.push(k);
			j->code = 2;
		}break;
		case 2: {
			printf("%d", j->p->val);
			j->code = 3;
		}break;
		case 3: {
			dat* l = Data(j->p->bro);
			s.push(l);
			j->code = 4;
		}break;
		case 4: {
			s.pop();
		}break;
		}
	}
	return;
}
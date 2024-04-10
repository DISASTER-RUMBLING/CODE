#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
using namespace std;

struct tree {
	int val;
	tree* kid, * bro;

};

tree* Init_Tree(int key) {
	tree* p = (tree*)malloc(sizeof(tree));
	p->val = key;
	p->bro = p->kid = NULL;

	return p;
}

tree* Insert_Tree(int key, tree* p) {
	if (p == NULL) {
		return Init_Tree(key);
	}
	if (p->val == key) {
		return p;
	}
	if (key > p->val) {
		p->bro = Insert_Tree(key, p->bro);
	}
	else {
		p->kid = Insert_Tree(key, p->kid);
	}
	return NULL;
}


tree* Erase_Tree(int key, tree* p) {
	if (p->val > key) {
		p->bro=Insert_Tree(key, p->bro);
	}
	else if (p->val < key) {
		p->kid=Insert_Tree(key, p->kid);
	}
	else {
		if (p->bro == NULL && p->kid == NULL) {
			Free_Tree(p);
			return NULL;
		}
		else if (p->bro == NULL || p->kid == NULL) {
			tree* q = p->bro ? p->bro : p->kid;
			Free_Tree(p);
			return q;
		}
		else {
			//´Ë´¦Ìæ»»Ç°Çý
			tree* q = p->kid;
			while (q->kid) {
				q = q->kid;
			}
			p->val = q->val;
			p->kid=Erase_Tree(p->val, q);
			return p;
		}
	}
}

void Free_Tree(tree* p) {
	if (p == NULL) {
		return;
	}
	Free_Tree(p->bro);
	Free_Tree(p->kid);
	free(p);

	return;
}
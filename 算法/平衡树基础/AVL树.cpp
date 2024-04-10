#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<cmath>
using namespace std;

struct tree {
	int val, high;
	tree* kid, * bro;

};

tree* Init_Tree(int key) {
	tree* p = (tree*)malloc(sizeof(tree));
	p->val = key;
	p->high = 1;
	p->bro = p->kid = NULL;
	return p;

}

void Update_High(tree* p) {
	if (p->bro == NULL && p->kid == NULL) {
		return;
	}
	else {
		p->high = p->bro->high > p->kid->high ? p->bro->high + 1 : p->kid->high + 1;
	}
	return;
}

tree* Right_Rorate(tree* p) {
	tree* new_root = p->kid;
	p->kid = new_root->kid;
	new_root->kid = p;
	Update_High(p);
	Update_High(new_root);
	return new_root;

}

tree* Left_Rorate(tree* p) {
	tree* new_root = p->bro;
	p->bro = new_root->kid;
	new_root->kid = p;
	Update_High(p);
	Update_High(new_root);
	return new_root;
	
}

tree* Maintain_Tree(tree* p) {
	if (abs(p->kid->high - p->bro->high) >= 1) {
		return p;
	}
	if (p->bro->high > p->kid->high) {//R型
		if (p->bro->kid->high > p->bro->bro->high) {
			//RL型
			p->bro = Right_Rorate(p->bro);
		}
		//RR型
		p = Left_Rorate(p);
	}
	else {//L型
		if (p->kid->kid->high < p->kid->bro->high) {
			//LR型
			p->kid = Left_Rorate(p->kid);
		}
		//LL型
		p = Right_Rorate(p);
	}
	return p;
}

tree* Erase_Tree(tree* p, int key) {
	if (p == NULL) {
		return NULL;
	}
	if (key > p->val) {
		p->bro = Erase_Tree(p->bro, key);
	}
	else if(key < p->val){
		p->kid = Erase_Tree(p->kid, key);
	}
	else {
		if (p->bro == NULL && p->kid == NULL) {//度为0
			Free_Tree(p);
			return NULL;
		}
		else if (p->bro != NULL && p->kid != NULL) {//度为2
			tree* temp = p;
			//此处替换前驱
			while (temp->kid) {
				temp = temp->kid;
			}
			p->val = temp->val;
			p->kid = Erase_Tree(temp, key);
			return p;
		}
		else  {//度为1
			tree* temp = p->bro == NULL ? p->kid : p->bro;
			free(p);
			return temp;
		}
	}
	
}

tree* Insert_Tree(tree* p, int key) {
	if (p == NULL) {
		return Init_Tree(key);
	}
	if (p->val == key) {
		return p;
	}
	if (key > p->val) {
		p->bro = Insert_Tree(p->bro, key);
	}
	else {
		p->kid = Insert_Tree(p->kid, key);
	}
	Update_High(p);
	return Maintain_Tree(p);
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
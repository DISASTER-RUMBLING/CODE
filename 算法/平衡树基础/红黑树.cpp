#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>

#define black 1
#define red 0
#define dblack 2

struct tree {
	int val, color;//0为红,1为黑,2为双重黑
	tree* bro, * kid;

};

tree _NIL, * NIL = &_NIL;

void Init__NIL() {
	NIL->val = -1;
	NIL->bro = NIL->kid = NULL;
	NIL->color = black;
}

tree* Init_Tree(int key) {
	tree* p = (tree*)malloc(sizeof(tree));
	p->val = key;
	p->bro = p->kid = NIL;
	p->color = red;
	return p;

}

tree* Left_Rorate(tree* p) {
	tree* new_root = p->bro;
	p->bro = new_root->kid;
	new_root->kid = p;
	return new_root;

}

tree* Right_Rorate(tree* p) {
	tree* new_root = p->kid;
	p->kid = new_root->bro;
	new_root->bro = p;
	return new_root;

}


tree* Insert_Maintain_Tree(tree* p) {
	if (p->kid->color == red && (p->kid->kid->color == red || p->kid->bro->color == red)) {
		if (p->bro->color == red && p->kid->color == red) {
			p->color = red;
			p->bro->color = p->kid->color = black;
		}
		if (p->kid->bro->color == red) {
			p->kid = Left_Rorate(p->kid);
		}
		p = Right_Rorate(p->bro);
	}
	else if (p->bro->color == red && (p->bro->kid->color == red || p->bro->bro->color == red)) {
		if (p->bro->color == red && p->kid->color == red) {
			p->color = red;
			p->bro->color = p->kid->color = black;
		}
		if (p->bro->kid->color == red) {
			p->bro = Right_Rorate(p->bro);
		}
		p = Left_Rorate(p->kid);
	}
	else {
		return p;
	}
	p->color = red;
	p->bro->color = p->kid->color = black;
	return p;
}

tree* _Insert_Tree(tree* p,int key) {
	if (p == NIL) {
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
	return Insert_Maintain_Tree(p);
}

tree* Insert_Tree(tree* p, int key) {
	p = _Insert_Tree(p, key);
	p->color = black;
	return p;

}

tree* Tree_Delete_Maintain(tree* p) {
	if (p->bro->color != dblack && p->kid->color != dblack) {
		return p;
	}
	if (p->bro->color == red || p->kid->color != red) {
		p->color = red;
		if (p->bro->color == red) {
			p = Right_Rorate(p);
			p->bro = Tree_Delete_Maintain(p->bro);
		}
		else {
			p = Left_Rorate(p);
			p->kid = Tree_Delete_Maintain(p->kid);
		}
		p->color = black;
		return p;
	}
	else {
		if (((p->kid->color == black) && (p->kid->kid->color == red || p->kid->bro->color == red)) ||
			(p->bro->color == black && (p->bro->kid->color == red || p->bro->bro->color == red))) {
			p->color += 1;
			p->bro->color--;
			p->kid->color--;
			return p;
		}
		if (p->bro->color == dblack) {
			p->bro->color = black;
			if (p->kid->kid->color != red) {
				p->kid = Left_Rorate(p->kid);
			}
			p->kid->color = p->color;
			p = Right_Rorate(p);
		}
		else {
			p->kid->color = black;
			if (p->bro->bro->color != red) {
				p->bro = Right_Rorate(p->bro);
			}
			p->bro->color = p->color;
			p = Left_Rorate(p);
		}
		p->bro->color = p->kid->color = black;
		return p;
	}
}

tree* _Tree_Delete(tree* p, int key) {
	if (p == NIL) {
		return p;
	}
	if (key > p->val) {
		p->bro = _Tree_Delete(p->bro, key);
	}
	else if (key < p->val) {
		p->kid = _Tree_Delete(p->kid, key);
	}
	else {
		if (p->bro == NIL || p->kid == NIL) {
			tree* temp = p->bro ? p->bro : p->kid;
			temp->color += p->color;
			free(p);
			return temp;
		}
		else {
			tree* temp = p;
			while (temp->kid != NIL) {
				temp = temp->kid;
			}
			p->val = temp->val;
			p->kid = _Tree_Delete(p->kid, p->val);
			return p;
		}
	}
}

tree* Tree_Delete(tree* p, int key) {
	p = _Tree_Delete(p, key);
	p->color = black;
	return p;

}

void Free_Tree(tree* p) {
	if (p == NIL) {
		return;
	}
	Free_Tree(p->bro);
	Free_Tree(p->kid);
	free(p);
	return;
}
#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<iostream>
#include<string.h>
using namespace std;

//假设节点中的最大关键字数量为4个

#define Max 4
struct tree {
	int n;
	int val[Max];
	tree* next[Max + 1];
};


tree* Init_Tree() {
	tree* p = (tree*)malloc(sizeof(tree));
	p->n = 0;
	memset(p->next, 0, sizeof(tree*) * (Max + 1));
	return p;

}

//插入及插入调整

tree* Insert_Maintain(tree* p, int pos) {
	tree* child = p->next[pos];
	if (Max > child->n) {
		return p;
	}
	int spos = Max / 2;
	tree* node1 = Init_Tree();
	tree* node2 = Init_Tree();
	node1->n = spos;
	node2->n = Max - 1 - spos;
	for (int i = 0; i < spos; i++) {
		node1->val[i] = child->val[i];
		node1->next[i] = child->next[i];
	}
	node1->next[spos] = child->next[spos];
	for (int i = 0; i < node2->n; i++) {
		node2->next[i] = child->next[i + spos + 1];
		node2->val[i] = child->val[i + spos + 1];
	}
	node2->next[node2->n] = child->next[child->n];
	for (int i = p->n; i > pos; i--) {
		p->next[i + 1] = p->next[i];
		p->val[i + 1] = p->val[i];
	}
	p->val[pos] = child->val[spos];
	p->next[pos] = node1;
	p->next[pos + 1] = node2;
	p->n++;
	free(child);
	return p;
}

tree* Insert_Num(int key, tree* p) {
	if (p == NULL) {
		tree* p = Init_Tree();
		p->val[p->n++] = key;
		return p;
	}
	else {
		int pos = 0;
		while (key > p->val[pos] && p->n > pos ) {
			pos++;
		}
		if (key == p->val[pos]) {
			return p;
		}
		for (int i = p->n - 1; i > pos; i--) {
			p->val[i + 1] = p->val[i];
		}
		p->val[pos] = key;
		p->n++;
		return p;
	}
}

tree* __Insert_Tree(int key, tree* p) {
	if (p == NULL && p->next[0] == NULL) {
		return Insert_Num(key, p);
	}
	int pos = 0;
	while (key > p->val[pos] && pos < p->n) {
		pos++;
	}
	if (pos < p->n && p->val[pos] == key) {
		return p;
	}
	p->next[pos] = __Insert_Tree(key, p->next[pos]);
	return Insert_Maintain(p, pos);
}

tree* Insert_Tree(int key, tree* p) {
	p = __Insert_Tree(key, p);
	if (Max < p->n) {
		tree* new_tree = Init_Tree();
		p->next[0] = new_tree;
		p = Insert_Maintain(p, 0);
	}
	return p;
}

//删除及删除调整，这里以替换前驱为例

void Right_Rorate(tree* p, int pos) {
	for (int i = p->next[pos + 1]->n; i > 0; i--) {
		p->next[pos + 1]->val[i] = p->next[pos + 1]->val[i - 1];
		p->next[pos + 1]->next[i] = p->next[pos + 1]->next[i - 1];
	}
	p->next[pos + 1]->val[0] = p->val[p->n - 1];
	p->next[pos + 1]->next[0] = p->next[pos]->next[p->n - 1];
	p->val[pos] = p->next[pos]->val[p->n - 1];
	p->next[pos]->val[p->n - 1] = NULL;
	p->next[pos]->next[p->n] = NULL;
	p->next[pos]->n--;
	p->next[pos + 1]->n++;
	return;
}

//根节点的关键字要放在pos-1的位置上
void Left_Rorate(tree* p, int pos) {
	p->next[pos-1]->val[p->next[pos-1]->n] = p->val[0];
	p->next[pos - 1]->next[p->next[pos - 1]->n] = p->next[pos]->next[0];
	for (int i = 0; i < p->n; i++) {
		p->val[i] = p->val[i + 1];
		p->next[i] = p->next[i + 1];
	}
	p->val[p->n - 1] = p->next[pos]->val[0];
	for (int i = 0; i < p->next[pos]->n; i++) {
		p->next[pos]->next[i] = p->next[pos]->next[i + 1];
		p->next[pos]->val[i] = p->next[pos]->val[i + 1];
	}
	p->next[pos]->next[p->next[pos]->n] = p->next[pos]->next[p->next[pos]->n + 1];
	p->next[pos]->val[p->next[pos]->n - 1] = NULL;
	p->next[pos]->next[p->next[pos]->n] = NULL;
	p->next[pos]->n--;
	return;
}

void Delete_Merge(tree* p, int pos) {
	tree* new_tree = Init_Tree();
	for (int i = 0; i < p->next[pos]->n; i++) {
		new_tree->next[i] = p->next[pos]->next[i];
		new_tree->val[i] = p->next[pos]->val[i];
	}
	new_tree->n = p->next[pos]->n + 1;
	new_tree->val[new_tree->n - 1] = p->val[pos];
	for (int i = 0; i < p->next[pos + 1]->n; i++) {
		new_tree->val[i + new_tree->n] = p->next[pos + 1]->val[i];
		new_tree->next[i + new_tree->n] = p->next[pos + 1]->next[i];
	}
	new_tree->n += p->next[pos + 1]->n;
	free(p->next[pos]);
	free(p->next[pos + 1]);
	for (int i = pos + 1; i <= p->n; i++) {
		p->val[i - 1] = p->val[i];
		p->next[i - 1] = p->next[i];
	}
	p->next[pos] = new_tree;
	p->n--;
	return;
}

tree* Delete_Maintain(tree* p, int pos) {
	int low = (Max + 1) / 2 - 1;
	if (low <= p->n) {
		return p;
	}
	if (p->next[pos - 1]->n > low) {
		Right_Rorate(p, pos);
	}
	else if ((pos + 1) < p->n && p->next[pos + 1]->n > low) {
		Left_Rorate(p, pos);
	}
	else {
		if (pos > 0) {
			Delete_Merge(p, pos - 1);//将pos和pos-1进行合并
		}
		else {
			Delete_Merge(p, pos);
		}
	}
	return p;
}

tree* Delete_Num(tree* p, int pos) {
	for (int i = pos - 1; i < p->n; i++) {
		p->val[i - 1] = p->val[i];
	}
	p->n--;
	return p;
}

tree* __Delete_Tree(int key, tree* p) {
	if (p == NULL) {
		return p;
	}
	int pos = 0;
	while (key < p->val[pos] && pos < p->n) {
		pos++;
	}
	if (p->next[0] == NULL) {
		if (key == p->val[pos]) {
			Delete_Num(p, pos);
		}
	}
	else {
		if (key == p->val[pos] && pos < p->n) {
			tree* pre = p->next[pos];
			while (pre->next[pre->n]) {
				pre = pre->next[pre->n];
			}
			p->val[pos] = pre->val[pre->n - 1];
			p->next[pos] = __Delete_Tree(key, p->next[pos]);
		}
		else {
			p->next[pos] = __Delete_Tree(key, p->next[pos]);
		}
	}
	return Delete_Maintain(p, pos);
}

tree* Delete_Tree(int key, tree* p) {
	p = __Delete_Tree(key, p);
	if (0 == p->n) {
		tree* temp = p->next[0];
		free(p);
		p = temp;
	}
	return p;
}

//

void Free_Tree(tree* p) {
	if (p == NULL) {
		return;
	}
	for (int i = 0; i < p->n; i++) {
		Free_Tree(p->next[i]);
	}
	free(p);
	return;
}
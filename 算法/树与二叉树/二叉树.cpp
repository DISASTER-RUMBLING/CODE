#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

typedef struct tree {
	int data;
	tree* bro, * kid;
}tree;

tree* Init_Tree(int val) {
	tree* p = (tree*)malloc(sizeof(tree));
	p->data = val;
	return p;
}

tree* Create_Tree(int* arr, int now_pos, int arr_size) {
	if (arr[now_pos] == '#') {
		return NULL;
	}
	tree* node = Init_Tree(arr[now_pos]);
	node->kid = Create_Tree(arr, now_pos + 1, arr_size);
	node->bro = Create_Tree(arr, 1 + now_pos, arr_size);
	return node;
}

tree* Insert(tree* p, int val) {
	if (p == NULL) {
		return Init_Tree(val);
	}
	srand(time(0));
	if (rand() % 2 == 1) {
		p->kid = Insert(p->kid, val);
	}
	else {
		p->bro = Insert(p->bro, val);
	}
	return p;
}

int Tree_Seek(tree* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (root->data == k) {
		return 1;
	}
	return Tree_Seek(root->bro, k) || Tree_Seek(root->kid, k);
}

int Tree_Size(tree* root) {
	if (root == NULL) {
		return 0;
	}
	return Tree_Size(root->bro) + Tree_Size(root->kid) + 1;
}

int Tree_Leaf_Num(tree* root) {
	if (root == NULL) {
		return 0;
	}
	int left = Tree_Leaf_Num(root->bro);
	int right = Tree_Leaf_Num(root->kid);
	if (left == right && left == 0) {
		return 1;
	}
	else {
		return left + right;
	}
}

int Tree_Level_Num(tree* root, int level) {
	if (root == NULL) {
		return 0;
	}
	queue<tree*> que;
	int now = 0;
	que.push(root);
	while (!que.empty() && now < level) {
		int sz = que.size();
		for (int i = 0; i < sz; i++) {
			tree* now_node = que.front();
			que.pop();
			if (now_node->bro != NULL) {
				que.push(now_node->bro);
			}
			if (now_node->kid != NULL) {
				que.push(now_node->kid);
			}
		}
		now++;
	}
	if (now + 1 < level) {
		return 0;
	}
	return que.size();
}

bool Complete_Tree_Check(tree* root) {
	if (root == NULL) {
		return false;
	}
	queue<tree*> que;
	que.push(root);
	while (!que.empty()) {
		tree* now_node = que.front();
		que.pop();
		if (now_node->kid != NULL) {
			que, push(now_node->kid);
		}
		else if (que.empty() || now_node->bro != NULL) {
			return false;
		}
		if (now_node->bro != NULL) {
			que.push(now_node->bro);
		}
		else if (que.empty()) {
			return false;
		}
	}
	return true;
}

void Free(tree* p) {
	if (p == NULL) {
		return;
	}
	Free(p->bro);
	Free(p->kid);
	return;
}

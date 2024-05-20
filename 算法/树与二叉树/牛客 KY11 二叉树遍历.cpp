#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct tree {
	char data;
	tree* left, * right;
};

tree* Init_Tree(char val) {
	tree* p = (tree*)malloc(sizeof(tree));
	p->data = val;
	return p;
}

tree* Create_Tree(string now, int& pos) {
	if (pos == now.size() || now[pos] == '#') {
		return NULL;
	}
	tree* root = Init_Tree(now[pos++]);
	root->left = Create_Tree(now, pos);
	pos++;
	root->right = Create_Tree(now, pos);
	return root;
}

void Tree_Inorder(tree* root) {
	if (root == NULL) {
		return;
	}
	Tree_Inorder(root->left);
	printf("%c ", root->data);
	Tree_Inorder(root->right);
	return;
}

int main() {

	string now;
	cin >> now;
	int pos = 0;
	tree* root = Create_Tree(now, pos);
	Tree_Inorder(root);

	return 0;
}
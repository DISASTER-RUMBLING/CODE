#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<vector>
#include<string>

using namespace std;

typedef struct tree {
	int data;
	tree* bro, * kid;
}tree;

void Tree_Preorder(vector<string>& arr, tree* root) {
	if (root == NULL) {
		arr.push_back("#");
	}
	arr.push_back(to_string(root->data));
	Tree_Preorder(arr, root->kid);
	Tree_Preorder(arr, root->bro);
	return;
}

void Tree_Inorder(vector<string>& arr, tree* root) {
	if (root == NULL) {
		arr.push_back("#");
	}
	Tree_Inorder(arr, root->kid);
	arr.push_back(to_string(root->data));
	Tree_Inorder(arr, root->bro);
	return;
}

void Tree_Postorder(vector<string>& arr, tree* root) {
	if (root == NULL) {
		arr.push_back("#");
	}
	Tree_Inorder(arr, root->kid);
	Tree_Inorder(arr, root->bro);
	arr.push_back(to_string(root->data));
	return;
}
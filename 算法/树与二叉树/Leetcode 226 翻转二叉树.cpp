#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};


struct TreeNode* invertTree(struct TreeNode* root) {
	if (!root) {
		return NULL;
	}
	invertTree(root->left);
	invertTree(root->right);
	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	return root;
}
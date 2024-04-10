#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* Init(int val) {
	struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	p->val = val;
	p->left = p->right = NULL;
	return p;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	if (preorderSize == 0) {
		return NULL;
	}
	struct TreeNode* root = Init(preorder[0]);
	int pos = 0;
	while (preorder[0] != inorder[pos]) {
		pos++;
	}
	int* lpre = (int*)malloc(sizeof(int) * (pos + 1)), * lin = (int*)malloc(sizeof(int) * (pos + 1));
	for (int i = 1; i <= pos; i++) {
		lpre[i - 1] = preorder[i];
		lin[i - 1] = inorder[i - 1];
	}
	root->left = buildTree(lpre, pos, lin, pos);
	free(lpre), free(lin);
	int* rpre = (int*)malloc(sizeof(int) * (inorderSize-pos-1)), * rin = (int*)malloc(sizeof(int) * (inorderSize - pos - 1));
	for (int i = pos+1,j=0; i < inorderSize; i++,j++) {
		rpre[j] = preorder[i];
		rin[j] = inorder[i];
	}
	root->right = buildTree(rpre, inorderSize - pos - 1, rin, inorderSize - pos - 1);
	free(rpre), free(rin);
	return root;
}

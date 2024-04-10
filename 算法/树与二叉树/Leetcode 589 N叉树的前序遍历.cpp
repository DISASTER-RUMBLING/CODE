#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int val;
	int numChildren;
	struct Node** children;
};

void Find(struct Node* root, int* result, int* returnsize) {
	if (root) {
		result[(*returnsize)++] = root->val;
		for (int i = 0; i < root->numChildren; i++) {
			Find(root->children[i], result, returnsize);
		}
	}
}

int* preorder(struct Node* root, int* returnSize) {
	int* result = (int*)malloc(10000 * sizeof(int));
	*returnSize = 0;
	if (root == NULL) {
		return result;
	}
	Find(root, result, returnSize);
	return result;
}
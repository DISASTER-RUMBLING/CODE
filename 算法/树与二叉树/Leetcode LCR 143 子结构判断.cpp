#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

bool Match(struct TreeNode* A, struct TreeNode* B) {
	if (A == NULL) {
		return (B == NULL);
	}
	if (B == NULL) {
		return true;
	}
	if (A->val != B->val) {
		return false;
	}
	return (Match(A->left, B->left) && Match(A->right, B->right));
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B) {
	if (A == NULL || B == NULL ) {
		return false;
	}
	if (A->val == B->val && Match(A, B)) {
		return true;
	}
	if (isSubStructure(A->left, B)) {
		return true;
	}
	if (isSubStructure(A->right, B)) {
		return true;
	}
	return false;
}


//ÓÅ»¯°æ
bool _isSubStructure_(struct TreeNode* A, struct TreeNode* B) {
	if (B == NULL) {
		return true;
	}
	if (A == NULL) {
		return false;
	}
	if (A->val == B->val) {
		return _isSubStructure_(A->left, B->left) || _isSubStructure_(A->right, B->right);
	}
	else {
		return false;
	}
}

bool _isSubStructure(struct TreeNode* A, struct TreeNode* B) {
	if (B == NULL || A == NULL ) {
		return false;
	}
	if (A->val == B->val) {
		if (_isSubStructure_(A, B)) {
			return true;
		}
		else if (_isSubStructure(A->left, B->left) || _isSubStructure(A->right, B->right)) {
			return true;
		}
	}
	else if (_isSubStructure(A->left, B) || _isSubStructure(A->right, B)) {
		return true;
	}
	return false;
}

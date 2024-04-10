#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

};

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	int** result = (int**)malloc(sizeof(int*) * 2000);
	*returnSize = 0;
	if (!root) {
		return NULL;
	}
	struct TreeNode* arr[2000];
	int columnSizes[2000];
	int head = 0, tail = 0;
	arr[tail++] = root;
	while (tail != head) {
		result[(*returnSize)] = (int*)malloc(sizeof(int) * (tail - head));
		columnSizes[(*returnSize)] = tail - head;
		int start = head;
		head = tail;
		for (int i = start; i < head; i++) {
			result[(*returnSize)][i - start] = arr[i]->val;
			if (arr[i]->left) {
				arr[tail++] = arr[i]->left;
			}
			if (arr[i]->right) {
				arr[tail++] = arr[i]->right;
			}
		}
		(*returnSize)++;
	}
	*returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < (*returnSize); i++) {
		(*returnColumnSizes)[i] = columnSizes[i];
	}
	for (int i = 0; 2 * i < *returnSize; ++i) {
		int* tmp1 = result[i];
		result[i] = result[(*returnSize) - i - 1];
		result[(*returnSize) - i - 1] = tmp1;
		int tmp2 = (*returnColumnSizes)[i];
		(*returnColumnSizes)[i] = (*returnColumnSizes)[(*returnSize) - i - 1];
		(*returnColumnSizes)[(*returnSize) - i - 1] = tmp2;
	}
	return result;
}
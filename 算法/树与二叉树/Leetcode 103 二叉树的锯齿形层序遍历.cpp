#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

};

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
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
			if ((*returnSize) % 2 == 0) {
				result[(*returnSize)][i - start] = arr[i]->val;
			}
			else {
				result[(*returnSize)][head - i -1] = arr[i]->val;
			}
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
	return result;
}
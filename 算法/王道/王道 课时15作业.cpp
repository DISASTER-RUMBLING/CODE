#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int arr[10], nums = 0;

struct Tree {
	int num;
	Tree* left, * rig;

	Tree(int val) :num(val),
		left(nullptr),
		rig(nullptr) {};
};

void In_Order(Tree* top) {
	if (top == nullptr) {
		return;
	}
	In_Order(top->left);
	arr[nums++] = top->num;
	In_Order(top->rig);
	return;
}

int main() {

	int p = 0;
	queue<Tree*> que;
	Tree* top = nullptr;
	for (int i = 0; i < 10;i++) {
		scanf("%d", &p);
		Tree* it = new Tree(p);
		if (top == nullptr) {
			top = it;
		}
		if (que.empty()) {
		}
		else if (que.front()->left == nullptr) {
			que.front()->left = it;
		}
		else {
			que.front()->rig = it;
			que.pop();
		}
		que.push(it);
	}
	In_Order(top);
	sort(arr, arr + 10);
	for (int i = 0; i < 10; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
	int l = 0, r = 10;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (arr[mid] > 21) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	printf("%d\n", l);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

struct Tree {
	char num;
	Tree* left, * rig;

	Tree(char val) :num(val),
		left(nullptr),
		rig(nullptr) {};
};

void Pre_Order(Tree* top) {
	if (top == nullptr) {
		return;
	}
	printf("%c", top->num);
	Pre_Order(top->left);
	Pre_Order(top->rig);
	return;

}

int main() {

	char p = 0;
	queue<Tree*> que;
	Tree* top = nullptr;
	while (1) {
		scanf("%c", &p);
		if (p == '\n') {
			break;
		}
		else {
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
	}
	Pre_Order(top);
	printf("\n");

	return 0;
}
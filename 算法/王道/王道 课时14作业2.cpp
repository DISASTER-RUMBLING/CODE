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

void In_Order(Tree* top) {
	if (top == nullptr) {
		return;
	}
	In_Order(top->left);
	printf("%c", top->num);
	In_Order(top->rig);
	return;
}

void Post_Order(Tree* top) {
	if (top == nullptr) {
		return;
	}
	Post_Order(top->left);
	Post_Order(top->rig);
	printf("%c", top->num);
	return;
}

void Bfs(Tree* top) {
	if (top == nullptr) {
		return;
	}
	queue<Tree*> que1;
	que1.push(top);
	while (!que1.empty()) {
		Tree* now = que1.front();
		que1.pop();
		printf("%c", now->num);
		if (now->left) {
			que1.push(now->left);
		}
		if (now->rig) {
			que1.push(now->rig);
		}
	}
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
	In_Order(top);
	printf("\n");
	Post_Order(top);
	printf("\n");
	Bfs(top);
	printf("\n");

	return 0;
}
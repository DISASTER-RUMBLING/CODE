#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct List {
	int num;
	List* next;

	List(int val) :num(val),
		next(nullptr) {};
};

int main() {

	int num;
	List* head = nullptr;
	List* now = nullptr;
	while (1) {
		scanf("%d", &num);
		if (num == 9999) {
			break;
		}
		List* it = new List(num);
		if (head == nullptr) {
			head = it;
		}
		if (now == nullptr) {
			now = it;
		}
		else {
			now->next = it;
			now = now->next;
		}
	}
	printf("%d\n", head->next->num);
	List* it = new List(99);
	it->next = head->next;
	head->next = it;
	List* nhead = head;
	while (head) {
		printf("%3d", head->num);
		head = head->next;
	}
	printf("\n");
	head = nhead;
	for (int i = 0; i < 2; i++) {
		nhead = nhead->next;
	}
	nhead->next = nhead->next->next;
	while (head) {
		printf("%3d", head->num);
		head = head->next;
	}
	printf("\n");
	return 0;
}
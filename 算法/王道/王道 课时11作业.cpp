#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>

using namespace std;

struct List
{
	int val;
	List* next;

	List(int num) :val(num)
		, next(nullptr) {};
};

int main() {

	int num = 0;
	List* head = nullptr, * now = nullptr;
	while (1) {
		scanf("%d", &num);
		if (num == 9999) {
			break;
		}
		List* it = new List(num);
		(it)->next = now;
		head = it;
		now = it;
	}
	while (head != nullptr) {
		printf("%d", head->val);
		if (head->next) {
			printf(" ");
		}
		else {
			printf("\n");
		}
		head = head->next;
	}
	head = nullptr;
	now = nullptr;
	while (1) {
		scanf("%d", &num);
		if (num == 9999) {
			break;
		}
		List* it =new List(num);
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
	while (head != nullptr) {
		printf("%d", head->val);
		if (head->next) {
			printf(" ");
		}
		else {
			printf("\n");
		}
		head = head->next;
	}
	printf("\n");

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int main() {

	int num;
	stack<int> sta;
	queue<int> que;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &num);
		sta.push(num);
	}
	while (!sta.empty()) {
		printf("%2d", sta.top());
		sta.pop();
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &num);
		if (i == 4) {
			printf("false\n");
		}
		else {
			que.push(num);
		}
	}
	while (!que.empty()) {
		printf("%2d", que.front());
		que.pop();
	}


	return 0;
}
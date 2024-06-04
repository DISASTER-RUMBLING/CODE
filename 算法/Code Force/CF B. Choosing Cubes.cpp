#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

int main() {

	int times;
	scanf("%d", &times);
	while (times--) {
		int n, f, k, like, flag = 0;
		scanf("%d%d%d", &n, &f, &k);
		priority_queue<int> que;
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			que.push(num);
			if (i == f-1) {
				like = num;
			}
		}
		for (int i = 0; i < k; i++) {
			if (que.top() == like) {
				flag++;
			}
			que.pop();
		}
		if (flag > 0) {
			if (!que.empty() && que.top() == like) {
				printf("MAYBE\n");
			}
			else {
				printf("YES\n");
			}
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}
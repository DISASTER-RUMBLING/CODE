#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int a, b, c, flag = 0;
int vis[9] = { 0 };
bool choi[11] = { 0 };

int check(int i) {
	int sum = 0;
	for (int j = (i * 3); j < (i + 1) * 3; j++) {
		sum *= 10;
		sum += vis[j];
	}
	return sum;
}

void dfs(int deep) {
	if (deep == 9) {
		if (check(0) * b == check(1) * a && check(0) * c == check(2) * a) {
			for (int i = 0; i < 9; i++) {
				if (i && !(i % 3)) {
					printf(" ");
				}
				printf("%d", vis[i]);
			}
			flag = 1;
			printf("\n");
		}
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (!choi[i]) {
			vis[deep] = i;
			choi[i] = i;
			dfs(deep + 1);
			vis[deep] = 0;
			choi[i] = 0;
		}
	}
}

int main() {
	
	scanf("%d%d%d", &a, &b, &c);
	dfs(0);
	if (!flag) {
		printf("No!!!");
	}

	return 0;
}
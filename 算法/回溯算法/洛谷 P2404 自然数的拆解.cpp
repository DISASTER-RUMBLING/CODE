#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int ans[20];

void Print(int n) {
	if (n == 1) {
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i) {
			printf("+");
		}
		printf("%d", ans[i]);
	}
	printf("\n");
	return;
}

void Deep_Seek(int step, int now, int n) {
	if (n == 0) {
		Print(step);
		return;
	}
	if (now > n) {
		return;
	}
	for (int i = now; i <= n; i++) {
		ans[step] = i;
		Deep_Seek(step + 1, i, n - i);
	}
	return;
}

int main() {

	int n;
	scanf("%d", &n);
	Deep_Seek(0, 1, n);

	return 0;

}
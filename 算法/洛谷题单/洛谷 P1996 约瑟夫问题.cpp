#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int n, m;
bool use[105] = { 0 };

int main() {

	scanf("%d%d", &n, &m);
	int times = 0, now =0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((++now) > n) {
				now = 1;
			}
			if (use[now]) {
				j--;
			}
		}
		printf("%d ", now);
		use[now] = 1;
	}

	return 0;
}
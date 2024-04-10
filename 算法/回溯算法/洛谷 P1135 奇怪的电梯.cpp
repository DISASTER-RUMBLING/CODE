#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
using namespace std;

//step表示现在是第几步，n表示最多有多少层，表示当前层数
void Target(int step, int a, int n, vector<int> &sou, vector<int> &tar) {
	if (step >= tar[a]) {
		return;
	}
	tar[a] = step;
	if (a + sou[a] <= n) {
		Target(step + 1, a + sou[a], n, sou, tar);
	}
	if (a - sou[a] >= 1) {
		Target(step + 1, a - sou[a], n, sou, tar);
	}
	return;
}

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	vector<int> sou(n + 1), res(n + 1, 0);
	for (int i = 1, k; i <= n; i++) {
		scanf("%d", &sou[i]);
		res[i] = n + 1;
	}
	Target(0, a, n, sou, res);
	printf("%d", res[b] == (n + 1) ? -1 : res[b]);

	return 0;
}
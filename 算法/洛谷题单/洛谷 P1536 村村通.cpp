#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Union {
	public:
		Union(int n) :fa(n + 1) {
			for (int i = 0; i <= n; i++) {
				fa[i] = i;
			}
		}
		int find(int i) {
			return fa[i] == i ? i : find(fa[i]);
		}
		void merge(int x, int y) {
			if (find(x) == find(y)) {
				return;
			}
			fa[find(x)] = find(y);
			return;
		}
		
		vector<int> fa;
};

int n, m;

int main() {

	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		scanf("%d", &m);
		Union u(n);
		while (m--) {
			int num1, num2;
			scanf("%d%d", &num1, &num2);
			u.merge(num1, num2);
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (u.find(i) == i) {
				res++;
			}
		}
		printf("%d\n", res - 1);
	}

	return 0;
}
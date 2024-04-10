#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Union {
	public:
		Union(int n) :fa(n + 1) {
			for (int i = 0; i < n; i++) {
				fa[i] = i;
			}
		}
		int find(int i) {
			return fa[i] = (fa[i] == i ? i : find(fa[i]));
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

int n, m, p;

int main() {

	scanf("%d%d%d", &n, &m, &p);
	Union u(n);
	while (m--) {
		int num1, num2;
		scanf("%d%d", &num1, &num2);
		u.merge(num1, num2);
	}
	while (p--) {
		int num1, num2;
		scanf("%d%d", &num1, &num2);
		if (u.find(num1) == u.find(num2)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}
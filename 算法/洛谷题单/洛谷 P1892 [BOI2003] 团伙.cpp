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

int n, num, per, tar;
char op;

int main() {

	scanf("%d", &n);
	Union u(2 * n);
	scanf("%d", &num);
	getchar();
	while (num--) {
		cin >> op >> per >> tar;
		if (op == 'E') {
			u.merge(n + per, tar);
			u.merge(n + tar, per);
		}
		else if (op == 'F') {
			u.merge(per, tar);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (u.find(i) == i) {
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
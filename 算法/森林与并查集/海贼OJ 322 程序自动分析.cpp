#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Unionset {
public:
	Unionset(int n) :fa(n + 1) {
		for (int i = 0; i <= n; i++) {
			fa[i] = i;
		}
	}

	int find(int n) {
		return fa[n] = (n == fa[n] ? n : find(fa[n]));
	}

	void merge(int x, int y) {
		fa[find(x)] = find(y);
		return;
	}

	vector<int> fa;
};

struct Data {
	int i, j, e;
};

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int flag = 1;
		scanf("%d", &m);
		Unionset u(2 * m);
		vector<Data> p;
		for (int k = 0, i, j, e; k < m; k++) {
			scanf("%d%d%d", &i, &j, &e);
			if (e == 1) {
				u.merge(i, j);
			}
			else {
				Data q;
				q.i = i;
				q.j = j;
				q.e = e;
				p.push_back(q);
			}
		}
		for (auto j : p) {
			if (u.find(j.i) == u.find(j.j)) {
				flag = 0;
			}
		}
		if (flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}
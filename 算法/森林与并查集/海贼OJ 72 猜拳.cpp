#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Unionset {
public:
	Unionset(int n) :fa(n + 1),val(n + 1) {
		for (int i = 0; i <= n; i++) {
			fa[i] = i;
			val[i] = 0;
		}
	}

	int find(int n) {
		if (fa[n] == n) {
			return n;
		}
		int root = find(fa[n]);
		val[n] = (val[n] + val[fa[n]]) % 3;
		return fa[n] = root;
	}

	void merge(int x, int y, int t) {
		int xx = find(x), yy = find(y);
		if (xx == yy) {
			return;
		}
		fa[xx] = yy;
		val[xx] = (t - val[x] + val[y] + 3) % 3;
		return;
	}

	vector<int> fa, val;
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Unionset u(n);
	for (int i = 0, a, b, c; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			u.merge(b, c, 2);
		}
		else {
			if (u.find(b) != u.find(c)) {
				printf("Unknown\n");
			}
			else {
				switch ((u.val[b] - u.val[c] + 3) % 3) {
				case 0: {
					printf("Tie\n");
					break;
				}
				case 1: {
					printf("Loss\n");
					break;
				}
				case 2: {
					printf("Win\n");
					break;
				}
				}
			}
		}
	}
	return 0;

}
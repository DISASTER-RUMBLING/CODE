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
		int find(int x) {
			return fa[x] = (fa[x] == x ? x : find(fa[x]));
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

int a, b, p;
bool arr[100005] = { 0 };

int main() {

	scanf("%d%d%d", &a, &b, &p);
	Union u(b);
	int ans = b - a + 1;
	//将全部素数(除了0和1)变为假
	for (int i = 2; i <= b; i++) {
		if (!arr[i]) {
			if (i >= p) {
				for (int j = i * 2; j <= b; j += i) {
					arr[j] = 1;
					if ((j - i) >= a && u.find(j) != u.find(j - i)) {
						u.merge(j, j - i);
						ans--;
					}
				}
			}
			else {
				for (int j = i * 2; j <= b; j += i) {
					arr[j] = 1;
				}
			}
		}
	}
	printf("%d", ans);

	return 0;
}
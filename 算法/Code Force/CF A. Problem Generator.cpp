#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>

using namespace std;

int main() {

	int times;
	scanf("%d", &times);
	while (times--) {
		int m, n;
		scanf("%d%d", &n, &m);
		getchar();
		map<char, int> mmp;
		for (int i = 0; i < n; i++) {
			char p;
			scanf("%c", &p);
			mmp[p] += 1;
		}
		int res = 0;
		for (int i = 0; i < m; i++) {
			for (char j = 'A'; j <= ('A' + 6); j++) {
				if (mmp[j] < 1) {
					res++;
					continue;
				}
				mmp[j]--;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}
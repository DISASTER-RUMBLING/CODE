#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;

int main() {

	int times;
	scanf("%d", &times);
	while (times--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int>> arr(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		if (n == 1 && m == 1) {
			printf("-1\n");
		}
		else {
			for (int i = 1; i < n; i++) {
				for (int j = 1; j < m; j++) {
					printf("%d ", arr[i][j]);
				}
				printf("%d\n", arr[i][0]);
			}
			for (int i = 1; i < m; i++) {
				printf("%d ", arr[0][i]);
			}
			printf("%d\n", arr[0][0]);
		}
	}

	return 0;
}
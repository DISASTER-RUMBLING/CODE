#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int n, m, beg, ed, res[100005];
vector<int> arr[100005];

void seek(int now, int last) {
	if (res[now]) {
		return;
	}
	res[now] = last;
	for (int i = 0; i < arr[now].size(); i++) {
		seek(arr[now][i], last);
	}
	return;
}

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &beg, &ed);
		arr[ed].push_back(beg);
	}
	for (int i = n; i > 0; i--) {
		seek(i, i);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");

	return 0;
}
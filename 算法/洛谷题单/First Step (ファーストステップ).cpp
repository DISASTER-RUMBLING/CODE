#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;

int r, c, k, times = 0;
unordered_map<int, int> now;
string p;
int arr[105][105] = { 0 };

void Check(int now) {
	for (int i = 0; i < c; i++) {
		if (p[i] == '.') {
			arr[now][i] = 1;
		}
	}
	return;
}

void dfs(int x, int y) {
	if (now.find(x * c + y) != now.end()) {
		return;
	}
	if (x == r || y == c) {
		return;
	}
	now.insert({ x * c + y, 1 });
	if (arr[x][y]) {
		if (k > 1) {
			int flag = 0;
			for (int i = 1, nx = x + 1; i < k; i++, nx++) {
				if (arr[nx][y] == 0) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				times++;
			}
			flag = 0;
			for (int i = 1, ny = y + 1; i < k; i++, ny++) {
				if (arr[x][ny] == 0) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				times++;
			}
		}
		else {
			int flag = 0;
			for (int i = 1, nx = x + 1; i < k; i++, nx++) {
				if (arr[nx][y] == 0) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				times++;
			}
		}
	}
	dfs(x + 1, y);
	dfs(x, y + 1);
	return;
}

int main() {

	scanf("%d%d%d", &r, &c, &k);
	for (int i = 0; i < r; i++) {
		cin >> p;
		Check(i);
	}
	dfs(0, 0);
	printf("%d", times);

	return 0;
}
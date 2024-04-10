#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int ans = 0, times[21] = { 0 };

int f(string& p1, string& p2) {
	for (int i = p1.size() - 1; i >= 1; i--) {
		int flag = 1;
		for (int j = 0; j < (p1.size() - i); j++) {
			if (p1[i + j] == p2[j]) {
				continue;
			}
			flag = 0;
			break;
		}
		if (flag == 1) {
			return p1.size() - i;
		}
	}
	return 0;
}

void Deep_Seek(int i, int len, int n, string* p,int coverge[21][21]) {
	times[i] += 1;
	if (len > ans) {
		ans = len;
	}
	for (int x = 0; x < n; x++) {
		if (coverge[i][x] == 0) {
			continue;
		}
		if (times[x] == 2) {
			continue;
		}
		Deep_Seek(x, (len + p[x].size() - coverge[i][x]), n, p, coverge);
	}
	times[i] -= 1;
	return;
}

int main() {
	string p[21];
	int n, coverge[21][21] = { 0 };
	char start;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	getchar();
	scanf("%c", &start);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			coverge[i][j] = f(p[i], p[j]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (p[i][0] != start) {
			continue;
		}
		Deep_Seek(i, p[i].size(), n, p, coverge);
	}
	printf("%d", ans);

	return 0;

}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;

char m[12][12];
//0号位置存坐标x，1号位置存坐标y，2号位置存方向
int times = 0, f[3], c[3];
unordered_map<int, int> p;

bool encounter() {
	if (c[0] == f[0] && c[1] == f[1]) {
		return true;
	}
	return false;
}

//0表示朝北，1表示朝东，2表示朝南，3表示朝西
void Move(int* arr) {
	int x = arr[0], y = arr[1];
	if (arr[2] == 0) {
		if (m[y - 1][x] == '*') {
			arr[2]++;
		}
		else {
			arr[1]--;
		}
	}
	else if (arr[2] == 1) {
		if (m[y][x + 1] == '*') {
			arr[2]++;
		}
		else {
			arr[0]++;
		}
	}
	else if (arr[2] == 2) {
		if (m[y + 1][x] == '*') {
			arr[2]++;
		}
		else {
			arr[1]++;
		}
	}
	else {
		if (m[y][x - 1] == '*') {
			arr[2] = 0;
		}
		else {
			arr[0]--;
		}
	}
	return;
}

int main() {

	for (int i = 0; i < 12; i++) {
		m[0][i] = '*';
		m[i][11] = '*';
		m[11][i] = '*';
		m[i][0] = '*';
	}
	//arr[0]表示列数，arr[1]表示行数
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cin >> m[i][j];
			if (m[i][j] == 'F') {
				f[1] = i;
				f[0] = j;
				f[2] = 0;
			}
			if (m[i][j] == 'C') {
				c[1] = i;
				c[0] = j;
				c[2] = 0;
			}
		}
	}
	while (!encounter()) {
		times++;
		int now = f[0] + f[1] * 10 + c[0] * 100 + c[1] * 1000 + f[2] * 10000 + c[2] * 40000;
		p.insert({ now, 1 });
		Move(c);
		Move(f);
		if (p.find(f[0] + f[1] * 10 + c[0] * 100 + c[1] * 1000 + f[2] * 10000 + c[2] * 40000) != p.end()) {
			printf("0");
			return 0;
		}
	}
	printf("%d", times);

	return 0;
}
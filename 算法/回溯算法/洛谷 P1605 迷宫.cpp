#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int map[6][6] = { 0 };
int dir[4][2] = {
	{0,1},{1,0},{0,-1},{-1,0}
};


int Deep_Seek(int nx, int ny, int ex, int ey) {
	if (nx == ex && ny == ey) {
		return 1;
	}
	int res = 0;
	map[nx][ny] = 0;
	for (int i = 0; i < 4; i++) {
		int dx = nx + dir[i][0];
		int dy = ny + dir[i][1];
		if (map[dx][dy] == 0) {
			continue;
		}
		res += Deep_Seek(dx, dy, ex, ey);
	}
	map[nx][ny] = 1;
	return res;
}

int main() {

	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = 1;
		}
	}
	int bx, by, ex, ey;
	scanf("%d%d%d%d", &bx, &by, &ex, &ey);
	for (int i = 0; i < t; i++) {
		int tx, ty;
		scanf("%d%d", &tx, &ty);
		map[tx][ty] = 0;
	}
	printf("%d", Deep_Seek(bx, by, ex, ey));

	return 0;

}
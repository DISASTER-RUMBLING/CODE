#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int x, y, n;
};

int dir[8][2] = {
	{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}
};
int dis[402][402];



void Deep_Seek(int x, int y, int n, int m) {
	queue<Node> p;
	Node now = { x,y,0 };
	p.push(now);
	dis[p.front().x][p.front().y] = 0;
	while (!p.empty()) {
		now = p.front();
		p.pop();
		for (int i = 0; i < 8; i++) {
			int dx = now.x + dir[i][0];
			int dy = now.y + dir[i][1];
			if (dx < 1 || dx > n) {
				continue;
			}
			if (dy < 1 || dy > m) {
				continue;
			}
			if (dis[dx][dy] != -1) {
				continue;
			}
			Node q = { dx,dy,now.n + 1 };
			p.push(q);
			dis[dx][dy] = q.n;
		}
	}
	return;
}

int main() {

	int n, m, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dis[i][j] = -1;
		}
	}
	Deep_Seek(x, y, n, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j > 1) {
				printf(" ");
			}
			printf("%d", dis[i][j]);
		}
		printf("\n");
	}

	return 0;

}
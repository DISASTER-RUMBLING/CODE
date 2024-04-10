#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int ax, ay, mx, my;
bool ma[25][25] = { 0 };
long long step[25][25] = { 0 };
int dir[9][2] = {
	{0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}
};

int main() {

	scanf("%d%d%d%d", &ax, &ay, &mx, &my);
	for (int i = 0; i < 9; i++) {
		ma[1 + mx + dir[i][0]][1 + my + dir[i][1]] = 1;
	}
	step[1][1] = 1;
	for (int i = 1; i <= (ax + 1); i++) {
		for (int j = 1; j <= (ay + 1); j++) {
			if (ma[i][j]) {
				continue;
			}
			step[i][j] += (step[i - 1][j] + step[i][j - 1]);
		}
	}
	printf("%lld", step[ax + 1][ay + 1]);

	return 0;
}
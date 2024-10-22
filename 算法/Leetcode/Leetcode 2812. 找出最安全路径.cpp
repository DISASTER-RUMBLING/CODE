#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:


	//                 ио     об     вС     ср
	int dir[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
	vector<vector<int>> arr;
	int row, col;

	void bfs(vector<vector<int>>& grid, int x, int y, int x_, int y_) {
		if (x < 0 || x >= row || y < 0 || y >= col || arr[x][y] == 0) {
			return;
		}
		int now = abs(x - x_) + abs(y - y_);
		if (now >= arr[x][y]) {
			return;
		}
		else {
			arr[x][y] = now;
		}
		for (int i = 0; i < 4; i++) {
			bfs(grid, x + dir[i][0], y + dir[i][1], x_, y_);
		}
		return;
	}

	bool Check(int x, int y, int mid, vector<vector<int>>& use) {
		if (x < 0 || x >= row || y < 0 || y >= col || use[x][y] || arr[x][y] < mid) {
			return false;
		}
		if (x == row - 1 && y == (col - 1)) {
			return true;
		}
		use[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			if (Check(x + dir[i][0], y + dir[i][1], mid, use)) {
				return true;
			}
		}
		return false;
	}

	int maximumSafenessFactor(vector<vector<int>>& grid) {
		row = grid.size(), col = grid[0].size();
		int l = -1, r = row + col + 1;
		arr = vector<vector<int>>(row, (vector<int>(col, 1e9)));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 1) {
					arr[i][j] = 0;
					for (int k = 0; k < 4; k++) {
						bfs(grid, i + dir[k][0], j + dir[k][1], i, j);
					}
				}
			}
		}
		while (l + 1 < r) {
			vector<vector<int>> use(row, (vector<int>(col, 0)));
			int mid = (l + r) / 2;
			if (Check(0, 0, mid, use)) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		return l;
	}


};
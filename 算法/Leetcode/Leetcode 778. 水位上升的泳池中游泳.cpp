#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:


	int n;
	int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };

	bool Check(vector<vector<int>>& grid, int mid, vector<int>& arr, int i, int j) {
		if (arr[i * n + j] || grid[i][j] > mid) {
			return false;
		}
		if (i == (n - 1) && j == (n - 1)) {
			return true;
		}
		arr[i * n + j] = 1;
		for (int k = 0; k < 4; k++) {
			int ni = i + dir[k][0], nj = j + dir[k][1];
			if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
				if (Check(grid, mid, arr, ni, nj)) {
					return true;
				}
			}
		}
		return false;
	}

	int swimInWater(vector<vector<int>>& grid) {
		int r = 0, l = -1;
		n = grid.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				r = max(r, grid[i][j]);
			}
		}
		r++;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			vector<int> arr(n * n, 0);
			if (Check(grid, mid, arr, 0, 0)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return r;
	}




};
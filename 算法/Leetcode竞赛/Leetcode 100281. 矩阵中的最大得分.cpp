#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

int maxScore(vector<vector<int>>& grid) {
	int sz = grid.size(), ans = -9999999;
	vector<vector<int>> res(sz);
	res[0].push_back(0);
	for (int i = 1; i < sz; i++) {
		res[i].push_back(max(grid[i][0] - grid[i - 1][0], res[i - 1][0] + grid[i][0] - grid[i - 1][0]));
		ans = max(res[i][0], ans);
	}
	for (int i = 0; i < sz; i++) {
		for (int j = 1; j < grid[0].size(); j++) {
			if (i == 0) {
				res[i].push_back(max(res[i][j - 1] + (grid[i][j] - grid[i][j - 1]), grid[i][j] - grid[i][j - 1]));
			}
			else {
				res[i].push_back(max(max(res[i - 1][j] + (grid[i][j] - grid[i - 1][j]), res[i][j - 1] + (grid[i][j] - grid[i][j - 1])), max((grid[i][j] - grid[i - 1][j]), grid[i][j] - grid[i][j - 1])));
			}
			ans = max(res[i][j], ans);
		}
	}
	return ans;
}
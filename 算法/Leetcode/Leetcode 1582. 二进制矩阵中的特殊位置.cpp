#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool check(vector<vector<int>>& mat, int row, int col) {
		for (int i = 0; i < mat[0].size(); i++) {
			if (mat[row][i] && i != col) {
				return 0;
			}
		}
		for (int i = 0; i < mat.size(); i++) {
			if (mat[i][col] && i != row) {
				return 0;
			}
		}
		return 1;
	}

	int numSpecial(vector<vector<int>>& mat) {
		int res = 0, row = mat.size(), col = mat[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (mat[i][j] && check(mat, i, j)) {
					res++;
				}
			}
		}
		return res;
	}
};
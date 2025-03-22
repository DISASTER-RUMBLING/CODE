#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
		int col = mat[0].size(), mx = 0, row = mat.size();
		vector<int> arr = { 0,0 };
		for (int i = 0; i < row; i++) {
			int num = 0;
			for (int j = 0; j < col; j++) {
				if (mat[i][j]) {
					num++;
				}
			}
			if (arr[1] < num) {
				arr[0] = i;
				arr[1] = num;
			}
		}
		return arr;
	}
};
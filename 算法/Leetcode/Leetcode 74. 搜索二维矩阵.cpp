#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int sz = matrix[0].size(), l = 0, r = matrix.size() * sz;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (matrix[mid / sz][mid % sz] > target) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return matrix[l / sz][l % sz] == target;
	}
};
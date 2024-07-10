#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<int> mx(matrix[0].size(), -1);
        for (int i = 0; i < matrix[0].size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                mx[i] = max(mx[i], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (-1 == matrix[i][j]) {
                    matrix[i][j] = mx[j];
                }
            }
        }
        return matrix;
    }
};
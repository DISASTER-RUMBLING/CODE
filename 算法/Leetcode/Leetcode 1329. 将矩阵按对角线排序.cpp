#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> Get(vector<vector<int>>& mat, int row, int col) {
        int n = mat[0].size(), m = mat.size();
        vector<int> arr;
        while (row < m && col < n) {
            arr.push_back(mat[row][col]);
            row++;
            col++;
        }
        sort(arr.begin(), arr.end());
        return arr;
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat[0].size(), m = mat.size();
        for (int i = 0; i < n - 1; i++) {
            vector<int> arr;
            arr = Get(mat, 0, i);
            int x = 0, y = i, j = 0;
            while (x < m && y < n) {
                mat[x++][y++] = arr[j++];
            }
        }
        for (int i = 1; i < m - 1; i++) {
            vector<int> arr;
            arr = Get(mat, i, 0);
            int x = i, y = 0, j = 0;
            while (x < m && y < n) {
                mat[x++][y++] = arr[j++];
            }
        }
        return mat;
    };

};
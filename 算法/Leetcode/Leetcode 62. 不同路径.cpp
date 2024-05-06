#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long long>> arr(m, vector<long long>(n, 0));
        for (int i = 0; i < m; i++) {
            arr[i][0] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (i == 0) {
                    arr[i][j] = (arr[i][j - 1]);
                }
                else {
                    arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]);
                }
            }
        }
        return arr[m - 1][n - 1];
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1) {
            if (obstacleGrid[0][0] == 1) {
                return 0;
            }
            return 1;
        }
        vector<vector<int>> res(obstacleGrid.size());
        for (int i = 0; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 1) {
                res[i].push_back(0);
            }
            else if (i != 0) {
                res[i].push_back(res[i - 1][0]);
            }
            else {
                res[i].push_back(1);
            }
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    res[i].push_back(0);
                }
                else if (i == 0) {
                    res[i].push_back(res[i][j - 1]);
                }
                else {
                    res[i].push_back(res[i][j - 1] + res[i - 1][j]);
                }
            }
        }
        return res[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }

};
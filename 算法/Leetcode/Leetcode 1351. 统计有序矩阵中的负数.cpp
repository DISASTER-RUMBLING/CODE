#include<vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = 0, col = 0, res = 0;
        int mr = grid.size(), mc = grid[0].size();
        if (grid[0][0] < 0) {
            return mr * mc;
        }
        while (row < mr) {
            while (col < mc && grid[row][col] >= 0) {
                col++;
            }
            while (col - 1 >= 0 && grid[row][col - 1] < 0) {
                col--;
            }
            res += mc - col;
            row++;
        }
        return res;
    }
};
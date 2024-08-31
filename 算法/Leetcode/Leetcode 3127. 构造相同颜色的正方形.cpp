#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 1; i < 3; i++) {
            for (int j = 1; j < 3; j++) {
                int w = 0, b = 0;
                if (grid[i][j] == 'W') {
                    w++;
                }
                else {
                    b++;
                }
                if (grid[i - 1][j] == 'W') {
                    w++;
                }
                else {
                    b++;
                }
                if (grid[i][j - 1] == 'W') {
                    w++;
                }
                else {
                    b++;
                }
                if (grid[i - 1][j - 1] == 'W') {
                    w++;
                }
                else {
                    b++;
                }
                if (w >= 3 || b >= 3) {
                    return true;
                }
            }
        }
        return false;
    }
};
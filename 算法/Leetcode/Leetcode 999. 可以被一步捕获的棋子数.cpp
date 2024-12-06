#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:


    int Check(vector<vector<char>>& board, int x, int y) {
        int x1 = x, y1 = y, res = 0;
        while (x1 >= 0) {
            if (board[x1][y] == 'p') {
                res++;
                break;
            }
            else if (board[x1][y] == 'B') {
                break;
            }
            x1--;
        }
        x1 = x;
        while (x1 < 8) {
            if (board[x1][y] == 'p') {
                res++;
                break;
            }
            else if (board[x1][y] == 'B') {
                break;
            }
            x1++;
        }
        while (y1 >= 0) {
            if (board[x][y1] == 'p') {
                res++;
                break;
            }
            else if (board[x][y1] == 'B') {
                break;
            }
            y1--;
        }
        y1 = y;
        while (y1 < 8) {
            if (board[x][y1] == 'p') {
                res++;
                break;
            }
            else if (board[x][y1] == 'B') {
                break;
            }
            y1++;
        }
        return res;
    }

    int numRookCaptures(vector<vector<char>>& board) {
        int x = 0, y = 0;
        for (; x < 8; x++) {
            for (y = 0; y < 8; y++) {
                if (board[x][y] == 'R') {
                    return Check(board, x, y);
                }
            }
        }
        return 0;
    }


};
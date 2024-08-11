#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int res = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == "UP") {
                res -= n;
            }
            else if (commands[i] == "RIGHT") {
                res += 1;
            }
            else if (commands[i] == "DOWN") {
                res += n;
            }
            else {
                res -= 1;
            }
        }
        return res;
    }
};
#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) {
        int flag = 1;
        while (x >= 1 && y >= 4) {
            x -= 1;
            y -= 4;
            flag = flag == 0 ? 1 : 0;
        }
        if (flag) {
            return "Bob";
        }
        else {
            return "Alice";
        }
    }
};
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
        int now = 0, flag = 0;
        while (k > 0) {
            if (!flag) {
                now++;
                k--;
                if (now == n - 1) {
                    flag = 1;
                }
            }
            else if (flag) {
                now--;
                k--;
                if (!now) {
                    flag = 0;
                }
            }
        }
        return now;
    }
};
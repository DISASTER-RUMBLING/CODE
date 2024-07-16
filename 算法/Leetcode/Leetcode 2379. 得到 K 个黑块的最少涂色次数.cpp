#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = 100, ans = 0, times = 0, l = 0;
        for (int i = 0; i < blocks.size(); i++) {
            if (ans == k) {
                res = min(times, res);
                if (blocks[l] == 'W') {
                    times = times > 0 ? times - 1 : 0;
                }
                ans--;
                l++;
            }
            if (blocks[i] == 'B') {
                ans++;
            }
            else {
                times++;
                ans++;
            }
        }
        res = min(res, times);
        return res;
    }
};
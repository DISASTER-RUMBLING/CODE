#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> res(n + 1);
        res[1] = 1;
        res[2] = 1;
        for (int i = 3; i <= n; i++) {
            int mx = 0;
            for (int j = 1; j <= (i / 2); j++) {
                int ans = max(res[i], max(j * (i - j), j * res[i - j]));
                mx = mx > ans ? mx : ans;
            }
            res[i] = mx;
        }
        return res[n];
    }
};
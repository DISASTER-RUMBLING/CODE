#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    int countHousePlacements(int n) {
        int mod = (1e9 + 7);
        vector<int> res(n + 1);
        res[1] = 2;
        res[0] = 1;
        for (int i = 2; i <= (n); i++) {
            res[i] = (res[i - 1] + res[i - 2]) % mod;
        }
        return (long long)res[n] * res[n] % mod;
    }

};
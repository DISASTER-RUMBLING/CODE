#define _CRT_SECURE_NO_WARNINGS
#include<map>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        map<int, long long> mmp;
        mmp[zero] += 1;
        mmp[one] += 1;
        long long res = 0;
        for (int i = min(min(zero, one) + 1, low); i <= high; i++) {
            mmp[i] += (mmp[i - zero] + mmp[i - one]) % (1000000007);
            if (i > low - 1) {
                res = (mmp[i] + res) % (1000000007);
            }
        }
        return (int)res;
    }
};
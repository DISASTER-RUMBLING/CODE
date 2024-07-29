#define _CRT_SECURE_NO_WARNINGS
#include<map>

using namespace std;

class Solution {
public:

    int nonSpecialCount(int l, int r) {
        int res = 0;
        map<int, int> mmp;
        long long now = sqrt(r);
        for (long long i = 2; i <= now; i++) {
            if (mmp[i]) {
                continue;
            }
            if ((i * i) >= l) {
                res++;
            }
            for (long long j = (i + i); j <= now; j += i) {
                mmp[j] = 1;
            }
        }
        return (r - l + 1) - res;
    }

};
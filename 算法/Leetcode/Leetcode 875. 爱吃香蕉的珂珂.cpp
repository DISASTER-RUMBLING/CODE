#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:


    long long times(vector<int>& piles, int v) {
        long long res = 0, sz = piles.size();
        for (long long i = 0; i < sz; i++) {
            res += (((piles[i] - 1) / v) + 1);
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long r = 0, sz = piles.size();
        for (long long i = 0; i < sz; i++) {
            r = max(r, (long long)piles[i]);
        }
        long long l = 0;
        while (l + 1 < r) {
            long long mid = (l + r) / 2;
            if (times(piles, mid) <= h) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }


};
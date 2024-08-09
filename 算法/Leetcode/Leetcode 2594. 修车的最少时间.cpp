#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& ranks, int cars, long long mid) {
        long long res = 0, sz = ranks.size();
        for (long long i = 0; i < sz; i++) {
            res += sqrt(mid / ranks[i]);
            if (res >= cars) {
                return true;
            }
        }
        return false;
    }


    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        long long l = 0, r = ((long long)(ranks[ranks.size() - 1])) * cars * cars;
        while (l + 1 < r) {
            long long mid = (l + r) >> 1;
            if (check(ranks, cars, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};
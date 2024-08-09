#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool times(vector<int>& dist, long long v, double tar) {
        long long sz = dist.size();
        double res = 0;
        for (long long i = 0; i < (sz - 1); i++) {
            res += ((dist[i] - 1 + v) / v);
        }
        res;
        res += (dist[sz - 1] / (v * 1.0));
        return (res) > tar;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int r = 1e7 + 1, sz = dist.size();
        if (hour <= sz - 1) {
            return -1;
        }
        long long l = 0;
        while (l + 1 < r) {
            long long mid = (r + l) / 2;
            if (times(dist, mid, hour)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return r;
    }

};
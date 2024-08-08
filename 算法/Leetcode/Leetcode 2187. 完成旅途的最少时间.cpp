#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long times(vector<int>& time, long long times) {
        long long res = 0, sz = time.size();
        for (int i = 0; i < sz; i++) {
            if (times < time[i]) {
                break;
            }
            res += ((times) / time[i]);
        }
        return res;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long sz = time.size(), r = 0;
        for (int i = 0; i < sz; i++) {
            r = max(r, (long long)time[i]);
        }
        if (totalTrips > time.size()) {
            r = r * (1 + ((totalTrips - 1) / time.size()));
        }
        long long l = 0;
        sort(time.begin(), time.end());
        while (l + 1 < r) {
            long long mid = (l + r) / 2;
            if (times(time, mid) < (long long)totalTrips) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return r;
    }
};
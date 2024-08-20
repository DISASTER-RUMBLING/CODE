#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    bool Check(int n, vector<int>& batteries, long long mid) {
        long long sz = batteries.size(), num = n, now = mid, last = 0;
        for (long long i = sz - 1; i >= 0; i--) {
            if ((long long)batteries[i] >= mid) {
                num--;
            }
            else if ((batteries[i] + last) >= now) {
                last = (batteries[i] + last - now);
                num--;
                now = mid;
            }
            else if ((batteries[i] + last) < now) {
                now -= (last + batteries[i]);
                last = 0;
            }
            if (!num) {
                return true;
            }
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0, r = 0, sz = batteries.size();
        sort(batteries.begin(), batteries.end());
        if (n == sz) {
            return batteries[0];
        }
        for (int i = 0; i < sz; i++) {
            r += batteries[i];
        }
        r = (r + n) / n;
        while (l + 1 < r) {
            long long mid = (l + r) >> 1;
            if (Check(n, batteries, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};
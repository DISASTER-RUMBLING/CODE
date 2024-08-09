#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    bool times(vector<int>& weights, int days, int mid) {
        int res = 0, now = 0, sz = weights.size();
        for (int i = 0; i < sz; i++) {
            if (now + weights[i] > mid) {
                res++;
                now = weights[i];
            }
            else if (now + weights[i] == mid) {
                res++;
                now = 0;
            }
            else {
                now += weights[i];
            }
        }
        if (now != 0) {
            res++;
        }
        return res <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int r = 0, sz = weights.size(), l = 0;
        for (int i = 0; i < sz; i++) {
            r += weights[i];
            l = max(l, weights[i]);
        }
        if (days >= sz) {
            return l;
        }
        l--;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (times(weights, days, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }

};
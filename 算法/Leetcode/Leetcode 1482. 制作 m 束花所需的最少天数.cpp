#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    bool Check(vector<int>& bloomDay, int m, int k, int mid) {
        int res = 0, sz = bloomDay.size(), now = 0;
        for (int i = 0; i < sz; i++) {
            if (bloomDay[i] <= mid) {
                now++;
                if (now == k) {
                    res++;
                    now = 0;
                    if (m == res) {
                        return true;
                    }
                }
            }
            else {
                now = 0;
            }
        }
        return false;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        if (((long long)(((long long)m) * ((long long)k))) > bloomDay.size()) {
            return -1;
        }
        int l = -1, r = 0, sz = bloomDay.size();
        for (int i = 0; i < sz; i++) {
            r = max(r, bloomDay[i]);
        }
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (Check(bloomDay, m, k, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};
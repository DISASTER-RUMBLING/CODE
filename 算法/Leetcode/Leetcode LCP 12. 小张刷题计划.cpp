#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:


    bool Check(vector<int>& time, int m, long long mid) {
        long long sz = time.size(), now = mid, mx = 0;
        for (long long i = 0; i < sz; i++) {
            if (time[i] > mx) {
                if (now <= mx) {
                    m--;
                    now = mid;
                }
                else {
                    now -= mx;
                }
                mx = time[i];
            }
            else {
                if (now <= time[i]) {
                    m--;
                    now = mid;
                    mx = time[i];
                }
                else {
                    now -= time[i];
                }
            }
        }
        return m > 0;
    }

    int minTime(vector<int>& time, int m) {
        int l = 0, r = 0, sz = time.size();
        for (int i = 0; i < sz; i++) {
            r += time[i];
        }
        r++;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (Check(time, m, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return l;
    }


};
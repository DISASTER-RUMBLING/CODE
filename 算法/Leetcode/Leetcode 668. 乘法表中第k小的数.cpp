#define _CRT_SECURE_NO_WARNINGS
#include<map>

using namespace std;

class Solution {
public:

    bool Check(int m, int n, int k, int mid) {
        int num = 0;
        for (int i = 1; i <= m; i++) {
            num += min(mid / i, n);
        }
        return num < k;
    }

    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (Check(m, n, k, mid)) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }

};
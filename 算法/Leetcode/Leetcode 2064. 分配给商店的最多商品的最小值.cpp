#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    bool Check(int n, vector<int>& quantities, int mid) {
        int res = 0, sz = quantities.size();
        for (int i = 0; i < sz; i++) {
            res += (quantities[i] / mid);
            if (quantities[i] % mid) {
                res++;
            }
            if (res > n) {
                return false;
            }
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0, r = 0, sz = quantities.size();
        for (int i = 0; i < sz; i++) {
            r = max(r, quantities[i]);
        }
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (Check(n, quantities, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};
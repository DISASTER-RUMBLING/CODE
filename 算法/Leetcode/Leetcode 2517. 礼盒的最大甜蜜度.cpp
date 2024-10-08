#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    bool Check(vector<int>& price, int k, int mid) {
        long long now = price[0], sz = price.size(), num = 1;
        for (int i = 1; i < sz; i++) {
            if (price[i] >= now + mid) {
                now = price[i];
                num++;
            }
            if (num == k) {
                return true;
            }
        }
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        long long l = 0, r = (*price.rbegin()) + 1;
        while (l + 1 < r) {
            long long mid = (l + r) >> 1;
            if (Check(price, k, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};
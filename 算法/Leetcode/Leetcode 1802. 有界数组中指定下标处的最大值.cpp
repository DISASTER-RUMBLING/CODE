#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Solution {
public:
    bool Check(long long n, long long index, long long maxSum, long long mid) {
        long long res = 0;
        if ((index + 1) >= mid) {
            res += ((1 + mid) * (mid) / 2);
            res += ((index + 1) - mid);
        }
        else {
            res += ((2 * mid - index) * (index + 1) / 2);
        }
        if ((n - index - 1) > (mid - 1)) {
            res += ((mid) * (mid - 1) / 2);
            res += (n - index - mid);
        }
        else {
            res += (2 * (mid - 1) - (n - index - 2)) * (n - index - 1) / 2;
        }
        return res <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        if (n == 1) {
            return maxSum;
        }
        long long l = 0, r = maxSum;
        while (l + 1 < r) {
            long long mid = (l + r) >> 1;
            if (Check(n, index, maxSum, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }


};
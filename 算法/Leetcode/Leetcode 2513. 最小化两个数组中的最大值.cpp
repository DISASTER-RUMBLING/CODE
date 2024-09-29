#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    bool Check(long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2, long long mid, long long lcm) {
        long long nums = mid / lcm;
        long long div1 = (mid / divisor2) - nums;
        long long div2 = (mid / divisor1) - nums;
        mid -= nums;
        if (div1 > uniqueCnt1) {
            mid -= (div1 - uniqueCnt1);
        }
        if (div2 > uniqueCnt2) {
            mid -= (div2 - uniqueCnt2);
        }
        return mid >= (uniqueCnt1 + uniqueCnt2);
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long l = 0, r = 1e10 + 7;
        long long lcm = ((long long)divisor1 * (long long)divisor2) / gcd(max(divisor1, divisor2), min(divisor1, divisor2));
        while (l < r) {
            long long mid = l + ((r - l) >> 1);
            if (Check(divisor1, divisor2, uniqueCnt1, uniqueCnt2, mid, lcm)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

};
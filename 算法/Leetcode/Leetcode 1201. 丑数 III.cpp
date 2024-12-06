#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Solution {
public:


	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}

	long long lcm(int a, int b) {
		return (long long)(((long long)a * (long long)b) / gcd(max(a, b), min(a, b)));
	}

	bool Check(int n, int a, int b, int c, long long mid, long long ab, long long ac, long long bc, long long abc) {
		long long a1 = mid / a, b1 = mid / b, c1 = mid / c, ab1 = mid / ab, ac1 = mid / ac, bc1 = mid / bc, abc1 = mid / abc;
		return (a1 + b1 + c1 - ab1 - ac1 - bc1 + abc1) >= n;
	}

	int nthUglyNumber(int n, int a, int b, int c) {
		long long l = 0, r = 1e10, ab = lcm(a, b);
		long long ac = lcm(a, c), bc = lcm(b, c);
		long long abc = lcm(lcm(a, b), c);
		while (l + 1 < r) {
			long long mid = (l + r) >> 1;
			if (Check(n, a, b, c, mid, ac, ab, bc, abc)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return r;
	}


};
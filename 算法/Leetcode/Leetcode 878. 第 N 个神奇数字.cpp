#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}

	bool Check(int n, int a, int b, long long mid, int mi) {
		long long a1 = mid / a, b1 = mid / b, ab1 = mid / mi;
		return (a1 + b1 - ab1) >= n;
	}

	int nthMagicalNumber(int n, int a, int b) {
		long long l = 0, r = 1LL * n * max(a, b), mod = 1e9 + 7;
		long long a1 = max(a, b), b1 = min(a, b), mi = (a * b) / gcd(a1, b1);
		while (l + 1 < r) {
			long long mid = (l + r) >> 1;
			if (Check(n, a1, b1, mid, mi)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return r % mod;
	}

};
#include<iostream>

using namespace std;

class Solution {
public:
	bool Check(long long mid, long long x) {
		return mid * mid > x;
	}

	int mySqrt(int x) {
		if (x == 1) {
			return x;
		}
		long long l = 0, r = x;
		while (l + 1 < r) {
			long long mid = (l + r) >> 1;
			if (Check(mid, x)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return l;
	}
};
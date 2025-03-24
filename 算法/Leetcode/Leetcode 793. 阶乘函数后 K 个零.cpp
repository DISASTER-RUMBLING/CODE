#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int Check(long long num) {
		long long res = 0, a = 5;
		while (a <= num) {
			res += (num / a);
			a *= 5;
		}
		return res;
	}

	int preimageSizeFZF(int k) {
		long long l = 4 * (long long)k - 1, r = 5 * (long long)k + 1;
		while (l + 1 < r) {
			long long mid = (l + r) >> 1;
			if (Check(mid) > k) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return Check(l) == k ? 5 : 0;
	}
};
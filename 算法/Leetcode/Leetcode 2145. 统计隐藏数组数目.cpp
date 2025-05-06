#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int numberOfArrays(vector<int>& differences, int lower, int upper) {
		int sz = differences.size();
		long long mx = 0, mi = 0, now = 0;
		for (int i = 0; i < sz; i++) {
			now += differences[i];
			mi = min(mi, now);
			mx = max(mx, now);
		}
		return (upper - lower) - (mx - mi) >= 0 ? (upper - lower) - (mx - mi) + 1 : 0;
	}
};
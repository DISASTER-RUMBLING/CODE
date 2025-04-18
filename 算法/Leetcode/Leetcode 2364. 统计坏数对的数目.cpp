#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	long long countBadPairs(vector<int>& nums) {
		long long res = 0;
		long long sz = nums.size();
		map<int, long long> mmp;
		for (int i = 0; i < sz; i++) {
			mmp[i - nums[i]] += 1;
		}
		for (auto x : mmp) {
			res += x.second * (x.second - 1) / 2;
		}
		return sz * (sz - 1) / 2 - res;
	}
};
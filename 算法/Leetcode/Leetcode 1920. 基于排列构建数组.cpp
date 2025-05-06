#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> buildArray(vector<int>& nums) {
		int sz = nums.size();
		vector<int> res(sz, 0);
		for (int i = 0; i < sz; i++) {
			res[i] = nums[nums[i]];
		}
		return res;
	}
};
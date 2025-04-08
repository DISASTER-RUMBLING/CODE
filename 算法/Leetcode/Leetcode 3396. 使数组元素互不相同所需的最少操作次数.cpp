#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		int sz = nums.size(), res = (sz / 3) + (sz % 3 ? 1 : 0);
		map<int, int> mmp;
		for (int i = sz - 1; i >= 0; i--) {
			if (mmp[nums[i]]) {
				res = (((i + 1) / 3) + ((i + 1) % 3 ? 1 : 0));
				return res;
			}
			mmp[nums[i]]++;
		}
		return 0;
	}
};
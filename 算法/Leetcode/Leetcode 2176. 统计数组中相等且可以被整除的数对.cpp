#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int countPairs(vector<int>& nums, int k) {
		int sz = nums.size(), res = 0;
		for (int i = 0; i < sz - 1; i++) {
			for (int j = i + 1; j < sz; j++) {
				if (nums[i] == nums[j] && !(i * j % k)) {
					res++;
				}
			}
		}
		return res;
	}
};
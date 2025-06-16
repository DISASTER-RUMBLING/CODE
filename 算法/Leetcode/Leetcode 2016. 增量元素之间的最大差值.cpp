#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int maximumDifference(vector<int>& nums) {
		int sz = nums.size(), l = nums[0], r = nums[1], res = -1;
		for (int i = 1; i < sz; i++) {
			if (nums[i] > r) {
				r = nums[i];
			}
			if (nums[i] < l) {
				if (r > l) {
					res = max(r - l, res);
				}
				if (i + 1 < sz) {
					l = nums[i];
					r = nums[i + 1];
				}
			}
		}
		return r > l ? max(r - l, res) : res;
	}
};
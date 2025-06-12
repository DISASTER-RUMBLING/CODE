#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int maxAdjacentDistance(vector<int>& nums) {
		int res = 0, sz = nums.size();
		for (int i = 0; i < sz; i++) {
			res = max(res, abs(nums[i] - nums[(i + 1) % sz]));
		}
		return res;
	}
};
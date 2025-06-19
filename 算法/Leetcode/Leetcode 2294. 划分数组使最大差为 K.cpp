#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int partitionArray(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int res = 0, l = 0, r = 0, sz = nums.size();
		while (r < sz) {
			while (r < sz && nums[r] - nums[l] <= k) {
				r++;
			}
			res++;
			l = r;
		}
		return res;
	}
};
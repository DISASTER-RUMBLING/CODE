#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> divideArray(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int num = 0, sz = nums.size();
		vector<vector<int>> res;
		for (int i = 0; i < sz - 2; i += 3) {
			if (nums[i + 2] - nums[i] <= k) {
				res.push_back({ nums[i], nums[i + 1], nums[i + 2] });
			}
			else {
				return {};
			}
		}
		return res;
	}
};
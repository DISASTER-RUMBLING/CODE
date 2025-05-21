#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool Check(vector<int>& nums, vector<vector<int>>& queries, int mid) {
		int sz = nums.size(), num = 0;
		vector<int> arr(sz + 1, 0);
		for (int i = 0; i < mid; i++) {
			arr[queries[i][0]] += queries[i][2];
			arr[queries[i][1] + 1] -= queries[i][2];
		}
		for (int i = 0; i < sz; i++) {
			num += arr[i];
			if (nums[i] > num) {
				return false;
			}
		}
		return true;
	}

	int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		int l = -1, r = queries.size();
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (Check(nums, queries, mid)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return Check(nums, queries, r) ? r : -1;
	}
};
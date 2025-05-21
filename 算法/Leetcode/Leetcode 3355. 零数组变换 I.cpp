#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		int sz = nums.size(), num = 0;
		vector<int> arr(sz + 1, 0);
		for (int i = 0; i < queries.size(); i++) {
			arr[queries[i][0]]++;
			arr[queries[i][1] + 1]--;
		}
		for (int i = 0; i < sz; i++) {
			num += arr[i];
			if (nums[i] > num) {
				return false;
			}
		}
		return true;
	}
};
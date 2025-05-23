#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	bool Check(int mid, vector<int>& nums, long long k) {
		long long num = 0, l = 0, res = 0;
		unordered_map<long long, long long> mmp;
		for (int r = 0; r < nums.size(); r++) {
			if (!mmp[nums[r]]) {
				num++;
			}
			mmp[nums[r]] += 1;
			while (l<r && num>mid) {
				mmp[nums[l]]--;
				if (!mmp[nums[l]]) {
					num--;
				}
				l++;
			}
			res += (r - l + 1);
		}
		return res >= k;
	}

	int medianOfUniquenessArray(vector<int>& nums) {
		int l = 0, r = nums.size();
		long long k = ((long long)nums.size() * (1 + nums.size()) / 2 + 1) / 2;
		while (l + 1 < r) {
			long long mid = (l + r) >> 1;
			if (Check(mid, nums, k)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return r;
	}




};
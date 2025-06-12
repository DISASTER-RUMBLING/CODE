#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void dfs(vector<int>& arr, long long num, long long mid, int now, int& res, int k) {
		if (res == k || now == arr.size() || num + arr[now] > mid) {
			return;
		}
		res++;
		dfs(arr, num, mid, now + 1, res, k);
		dfs(arr, num + arr[now], mid, now + 1, res, k);
		return;
	}

	bool Check(long long mid, long long num, vector<int>& arr, int k) {
		int res = 1;
		dfs(arr, 0, mid, 0, res, k);
		return res == k;
	}

	long long kSum(vector<int>& nums, int k) {
		long long num = 0, sz = nums.size(), res = 0;
		for (int i = 0; i < sz; i++) {
			if (nums[i] < 0) {
				nums[i] *= -1;
			}
			else {
				res += nums[i];
			}
			num += nums[i];
		}
		sort(nums.begin(), nums.end());
		long long l = -1, r = num;
		while (l + 1 < r) {
			long long mid = (l + r) >> 1;
			if (Check(mid, num, nums, k)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		return res - r;
	}
};
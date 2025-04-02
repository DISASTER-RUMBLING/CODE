#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	long long maximumTripletValue(vector<int>& nums) {
		int front = 0, rear = 2, sz = nums.size(), num = nums[0];
		vector<int> arr(sz, 0);
		long long res = 0;
		for (int i = 1; i < sz; i++) {
			arr[i] = max(0, num - nums[i]);
			num = max(nums[i], num);
		}
		num = arr[1];//num[i]-num[j]
		int flag = 0;
		int num1 = nums[2];//num[k]
		for (int i = 2; i < sz; i++) {
			num1 = max(num1, nums[i]);
			if (flag) {
				flag = 0;
				num1 = nums[i];
			}
			res = max(res, ((long long)num * (long long)num1));
			arr[i] > num ? flag = 1 : 0;
			num = max(arr[i], num);
		}
		return res;
	}
};
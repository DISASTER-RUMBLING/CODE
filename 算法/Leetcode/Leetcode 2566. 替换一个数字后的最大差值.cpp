#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int minMaxDifference(int num) {
		string nums = to_string(num);
		int now = -1, sz = nums.size(), res = 0, flag = -1;
		for (int i = sz - 1; i >= 0; i--) {
			if (nums[i] != '9') {
				now = i;
			}
		}
		for (int i = sz - 1; i >= 0; i--) {
			if (nums[i] != '0') {
				flag = i;
			}
		}
		if (now == -1) {
			return num;
		}
		for (int i = 0; i < sz; i++) {
			int flag1 = 0, flag2 = 0;
			if (nums[i] == nums[now]) {
				flag1 = '9';
			}
			else {
				flag1 = nums[i];
			}
			if (nums[i] == nums[flag]) {
				flag2 = '0';
			}
			else {
				flag2 = nums[i];
			}
			res = res * 10 + (flag1 - flag2);
		}
		return res;
	}
};
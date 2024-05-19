#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
	bool isArraySpecial(vector<int>& nums) {
		int sz = nums.size();
		if (sz < 2) {
			return true;
		}
		int now = 0;
		while (now < (sz - 1)) {
			if ((nums[now] % 2) + (nums[now + 1] % 2) != 1) {
				return false;
			}
			now++;
		}
		return true;
	}
};
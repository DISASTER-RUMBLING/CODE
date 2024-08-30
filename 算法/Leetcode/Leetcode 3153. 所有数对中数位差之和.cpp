#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:


	long long sumDigitDifferences(vector<int>& nums) {
		vector<vector<int>> arr(10, vector<int>(10, 0));
		long long res = 0, sz = nums.size();
		for (long long i = 0; i < sz; i++) {
			int now = 0, num = nums[i];
			while (num > 0) {
				res += (i - arr[now][num % 10]);
				arr[now][num % 10] += 1;
				now++;
				num /= 10;
			}
		}
		return res;
	}


};
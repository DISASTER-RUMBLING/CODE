#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	long long minSum(vector<int>& nums1, vector<int>& nums2) {
		long long sz1 = nums1.size(), sz2 = nums2.size(), sum1 = 0, sum2 = 0, flag1 = 0, flag2 = 0;
		for (int i = 0; i < sz1; i++) {
			sum1 += nums1[i];
			if (!nums1[i]) {
				flag1 += 1;
			}
		}
		for (int i = 0; i < sz2; i++) {
			sum2 += nums2[i];
			if (!nums2[i]) {
				flag2 += 1;
			}
		}
		if (!flag1 && sum1 < flag2 + sum2) {
			return -1;
		}
		else if (!flag2 && sum1 + flag1 > sum2) {
			return -1;
		}
		if (sum1 == sum2) {
			return flag1 > flag2 ? sum1 + flag1 : sum2 + flag2;
		}
		return sum1 + flag1 > flag2 + sum2 ? sum1 + flag1 : (sum2 + flag2);
	}
};
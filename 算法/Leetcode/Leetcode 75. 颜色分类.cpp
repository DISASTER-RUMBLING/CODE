#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums.size() - i - 1; j++) {
				if (nums[j] > nums[j + 1]) {
					int num = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = num;
				}
			}
		}
		return;
	}
};
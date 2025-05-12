#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> findEvenNumbers(vector<int>& digits) {
		int sz = digits.size();
		vector<int> res, count(10, 0);
		for (int i = 0; i < sz; i++) {
			count[digits[i]] += 1;
		}
		for (int i = 100; i < 999; i += 2) {
			int j = i % 10, k = (i / 10) % 10, l = i / 100;
			count[j]--, count[k]--, count[l]--;
			if (count[j] >= 0 && count[k] >= 0 && count[l] >= 0) {
				res.push_back(i);
			}
			count[j]++, count[k]++, count[l]++;
		}
		return res;
	}
};
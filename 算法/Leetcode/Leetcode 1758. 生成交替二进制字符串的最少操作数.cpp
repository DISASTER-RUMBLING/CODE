#include<iostream>

using namespace std;

class Solution {
public:
	int minOperations(string s) {
		int res1 = 0, res2 = 0, sz = s.size();
		for (int i = 0; i < sz; i++) {
			if (i % 2) {
				if (s[i] == '0') {
					res1++;
				}
			}
			else {
				if (s[i] == '1') {
					res1++;
				}
			}
			if (i % 2) {
				if (s[i] == '1') {
					res2++;
				}
			}
			else {
				if (s[i] == '0') {
					res2++;
				}
			}
		}
		return min(res1, res2);
	}
};
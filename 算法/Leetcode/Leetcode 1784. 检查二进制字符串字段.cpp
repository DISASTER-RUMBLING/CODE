#include<iostream>

using namespace std;

class Solution {
public:
	bool checkOnesSegment(string s) {
		int res = 0, sz = s.size(), flag = 0;
		for (int i = 0; i < sz; i++) {
			if (s[i] == '1') {
				if (!flag) {
					res++;
					flag = 1;
				}
			}
			else if (s[i] == '0') {
				if (flag) {
					flag = 0;
				}
			}
		}
		return res < 2;
	}
};
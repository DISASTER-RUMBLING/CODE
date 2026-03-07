#include<iostream>

using namespace std;

class Solution {
public:
	int minFlips(string s) {
		int sz = s.size(), tmp = 0, res = sz;
		for (int i = 0; i < 2 * sz - 1; i++) {
			if (s[i % sz] % 2 != i % 2) {
				tmp++;
			}
			int l = i - sz + 1;
			if (l < 0) {
				continue;
			}
			res = min({ res,tmp,sz - tmp });
			if (s[l % sz] % 2 != l % 2) {
				tmp--;
			}
		}
		return res;
	}
};
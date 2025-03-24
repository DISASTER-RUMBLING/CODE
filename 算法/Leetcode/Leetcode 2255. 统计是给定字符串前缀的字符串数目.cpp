#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
	int countPrefixes(vector<string>& words, string s) {
		int res = 0, sz = s.size();
		map<string, bool> mmp;
		for (int i = 0; i <= sz; i++) {
			mmp[s.substr(0, i)] = 1;
		}
		sz = words.size();
		for (int i = 0; i < sz; i++) {
			if (mmp[words[i]]) {
				res++;
			}
		}
		return res;
	}
};
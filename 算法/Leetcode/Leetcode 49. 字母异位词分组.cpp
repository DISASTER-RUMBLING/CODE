#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int sz = strs.size();
		unordered_map<string, vector<string>> mmp;
		for (int i = 0; i < sz; i++) {
			string now = strs[i];
			sort(now.begin(), now.end());
			mmp[now].push_back(strs[i]);
		}
		vector<vector<string>> res;
		for (auto i : mmp) {
			res.push_back(i.second);
		}
		return res;
	}
};
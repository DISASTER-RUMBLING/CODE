#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	string res;

	bool dfs(string now, unordered_map< string, bool >& mmp, int lon) {
		if (now.size() == lon && !mmp[now]) {
			res = now;
			return 1;
		}
		if (now.size() > lon) return 0;
		if (now.size() == lon && mmp[now])return 0;
		if (dfs(now + '1', mmp, lon)) return 1;
		else if (dfs(now + '0', mmp, lon)) return 1;
		return 0;
	}

	string findDifferentBinaryString(vector<string>& nums) {
		unordered_map<string, bool> mmp;
		int sz = nums.size(), lon = nums[0].size();
		for (int i = 0; i < sz; i++) {
			mmp[nums[i]] = 1;
		}
		dfs("", mmp, lon);
		return res;
	}
};
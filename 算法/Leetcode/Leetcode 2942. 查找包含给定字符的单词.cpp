#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> findWordsContaining(vector<string>& words, char x) {
		vector<int> res;
		int sz = words.size();
		for (int i = 0; i < sz; i++) {
			if (words[i].find(x) != string::npos) {
				res.push_back(i);
			}
		}
		return res;
	}
};
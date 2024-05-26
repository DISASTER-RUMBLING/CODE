#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	string compressedString(string word) {
		int sz = word.size(), now = 0;
		string res;
		while (now < sz) {
			int times = 0;
			while ((!times || word[now - 1] == word[now]) && times < 9) {
				times++;
				now++;
			}
			res.push_back(times + '0');
			res.push_back(word[now - 1]);
		}
		return res;
	}
};
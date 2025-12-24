#include<iostream>

using namespace std;

class Solution {
public:
	int possibleStringCount(string word) {
		int res = 1, num = 0;
		for (int i = 1; i < word.size(); i++) {
			if (word[i - 1] == word[i]) {
				num++;
			}
			else {
				res += num;
				num = 0;
			}
		}
		return res + num;
	}
};
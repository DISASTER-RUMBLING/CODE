#include<iostream>

using namespace std;

class Solution {
public:
	string answerString(string word, int numFriends) {
		if (numFriends == 1) {
			return word;
		}
		int sz = word.size();
		string res;
		if (sz == numFriends) {
			char a = word[0];
			for (int i = 1; i < sz; i++) {
				if (word[i] > a) {
					a = word[i];
				}
			}
			res = a;
		}
		else {
			int num = sz - numFriends;
			res = word.substr(0, num + 1);
			for (int i = 1; i <= sz; i++) {
				string now = word.substr(i, num + 1);
				if (now > res) {
					res = now;
				}
			}
		}
		return res;
	}
};
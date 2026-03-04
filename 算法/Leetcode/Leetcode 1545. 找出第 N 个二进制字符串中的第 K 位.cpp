#include<iostream>

using namespace std;

class Solution {
public:
	char findKthBit(int n, int k) {
		string res = "0";
		while (res.size() - 1 < k) {
			string tmp = "";
			for (int i = res.size() - 1; i >= 0; i--) {
				if (res[i] == '0') {
					tmp.push_back('1');
				}
				else {
					tmp.push_back('0');
				}
			}
			res.push_back('1');
			res = res + tmp;
		}
		return res[k - 1];
	}
};
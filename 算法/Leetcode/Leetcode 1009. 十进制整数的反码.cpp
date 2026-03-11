#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int bitwiseComplement(int n) {
		if (!n) return 1;
		vector<int> res;
		int num = n;
		while (num) {
			res.push_back((num % 2) == 1 ? 0 : 1);
			num /= 2;
		}
		num = 0;
		int sz = res.size();
		for (int i = sz - 1; i >= 0; i--) {
			num *= 2;
			num += res[i];
		}
		return num;
	}
};
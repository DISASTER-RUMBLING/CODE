#include<iostream>

using namespace std;

class Solution {
public:
	int differenceOfSums(int n, int m) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += (i % m ? 1 : -1) * i;
		}
		return res;
	}
};
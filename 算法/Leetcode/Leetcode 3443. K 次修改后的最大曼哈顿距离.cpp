#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int maxDistance(string s, int k) {
		int res = 0, sz = s.size(), up = 0, lr = 0;
		for (int j = 0; j < sz; j++) {
			if (s[j] == 'N') {
				up++;
			}
			else if (s[j] == 'S') {
				up--;
			}
			else if (s[j] == 'W') {
				lr--;
			}
			else {
				lr++;
			}
			res = max(res, min(abs(up) + abs(lr) + 2 * k, 1 + j));
		}
		return res;
	}
};
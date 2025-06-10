#include<iostream>

using namespace std;

class Solution {
public:
	int maxDifference(string s) {
		int arr[26] = { 0 };
		int sz = s.size();
		for (int i = 0; i < sz; i++) {
			arr[(int)(s[i] - 'a')]++;
		}
		int smx = 0, dmi = 1e9;
		for (int i = 0; i < 26; i++) {
			if (!arr[i]) {
				continue;
			}
			else {
				if (arr[i] % 2) {
					smx = max(smx, arr[i]);
				}
				else {
					dmi = min(dmi, arr[i]);
				}
			}
		}
		return smx - dmi;
	}
};
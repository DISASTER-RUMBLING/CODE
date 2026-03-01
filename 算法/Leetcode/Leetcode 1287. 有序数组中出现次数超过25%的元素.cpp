#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		if (arr.size() == 1) {
			return arr[0];
		}
		int n = arr.size() / 4;
		for (int i = n; i < arr.size(); i += n + 1) {
			int l = 0, r = i, mid;
			while (l + 1 < r) {
				mid = (l + r) >> 1;
				if (arr[mid] < arr[i]) l = mid;
				else r = mid;
			}
			if (arr[l + n + 1] == arr[i])return arr[i];
		}
		return arr[0];
	}
};
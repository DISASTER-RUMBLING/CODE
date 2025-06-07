#include<iostream>

using namespace std;

class Solution {
public:
	int find(int x, int* arr) {
		if (x != arr[x]) {
			return arr[x] = find(arr[x], arr);
		}
		return x;
	}

	void merge(int x, int y, int* arr) {
		int x1 = find(x, arr), y1 = find(y, arr);
		if (x1 < y1) {
			arr[y1] = x1;
		}
		else if (y1 < x1) {
			arr[x1] = y1;
		}
		return;
	}

	string smallestEquivalentString(string s1, string s2, string baseStr) {
		int arr[26] = { 0 };
		for (int i = 0; i < 26; i++) {
			arr[i] = i;
		}
		int sz = s1.size();
		for (int i = 0; i < sz; i++) {
			merge(s1[i] - 'a', s2[i] - 'a', arr);
		}
		sz = baseStr.size();
		for (int i = 0; i < sz; i++) {
			baseStr[i] = (char)('a' + find((int)(baseStr[i] - 'a'), arr));
		}
		return baseStr;
	}
};
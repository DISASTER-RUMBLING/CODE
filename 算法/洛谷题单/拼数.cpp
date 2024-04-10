#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string p1, string p2) {
	return p1 + p2 > p2 + p1;
}

int main() {

	int n;
	vector<string> arr;
	scanf("%d", &n);
	string p;
	for (int i = 0; i < n; i++) {
		cin >> p;
		arr.push_back(p);
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << *arr.begin();
		arr.erase(arr.begin());
	}

	return 0;
}
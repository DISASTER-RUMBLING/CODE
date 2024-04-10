#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool Cmp(string& s1, string& s2) {
	return s1 + s2 > s2 + s1;
}

int main() {
	
	int n;
	scanf("%d", &n);
	vector<string> arr;
	string now;
	for (int i = 0; i < n; i++) {
		cin >> now;
		arr.push_back(now);
	}
	sort(arr.begin(), arr.end(), Cmp);
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}

	return 0;

}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main() {

	string p1, p2;
	cin >> p1;
	cin >> p2;
	vector<int> num1, num2, sum;
	int len1 = p1.length();
	int len2 = p2.length();
	int len = len1 > len2 ? len1 : len2;
	for (int i = 0, x, y; i < len; i++) {
		if (i < len1) {
			num1.insert(num1.begin(), p1[i] - '0');
		}
		else {
			num1.push_back(0);
		}
		if (i < len2) {
			num2.insert(num2.begin(), p2[i] - '0');
		}
		else {
			num2.push_back(0);
		}
	}
	int flag = 0;
	while (!num1.empty() || !num2.empty()) {
		int x = *num1.begin();
		int y = *num2.begin();
		if ((x + y + flag) > 9) {
			sum.insert(sum.begin(), (x + y + flag) % 10);
			flag = 1;
		}
		else {
			sum.insert(sum.begin(), x + y + flag);
			flag = 0;
		}
		num1.erase(num1.begin());
		num2.erase(num2.begin());
	}
	if (flag) {
		sum.insert(sum.begin(), flag);
	}
	while (!sum.empty()) {
		cout << *sum.begin();
		sum.erase(sum.begin());
	}

	return 0;
}
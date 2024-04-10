#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main() {

	string p1, p2;
	cin >> p1;
	cin >> p2;
	int len1 = p1.size(), len2 = p2.size();
	int len = max(len1, len2);
	int num1[2005], num2[2005], res[10001] = { 0 };
	int flag = 0;
	for (int i = 1; i <= len; i++) {
		if (i <= len1) {
			num1[i] = p1[len1 - i] - '0';
		}
		if (i <= len2) {
			num2[i] = p2[len2 - i] - '0';
		}
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			res[j + i - 1] += (num1[i] * num2[j]);
		}
	}
	for (int i = 1; res[i]; i++) {
		if (res[i] > 9) {
			res[i + 1] += (res[i] / 10);
			res[i] %= 10;
		}
	}
	len = len1 + len2;
	while (res[len] == 0 && len > 1) {
		len--;
	}
	for (int i = len; i >= 1; i--) {
		cout << res[i];
	}
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		int num, res = 0;
		cin >> num;
		while (num > 0) {
			res += (num % 10);
			num /= 10;
		}
		cout << res << endl;
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		int num;
		cin >> num;
		if ((num % 2) == 1) {
			for (int i = 1; i <= num; i += 2) {
				cout << i << " ";
			}
			for (int i = num - 1; i > 0; i -= 2) {
				cout << i << " ";
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	return 0;
}
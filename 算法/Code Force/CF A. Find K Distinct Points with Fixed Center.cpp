#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		int x, y, k;
		cin >> x >> y >> k;
		if (k == 1) {
			cout << x << " " << y << endl;
		}
		else if (k % 2) {
			cout << x << " " << y << endl;
			for (int i = 1; i <= (k / 2); i++) {
				cout << (x - i) << " " << (y - i) << endl;
				cout << (x + i) << " " << (y + i) << endl;
			}
		}
		else {
			for (int i = 1; i <= (k / 2); i++) {
				cout << (x - i) << " " << (y - i) << endl;
				cout << (x + i) << " " << (y + i) << endl;
			}
		}
	}

	return 0;
}